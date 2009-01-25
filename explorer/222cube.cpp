
#include "222cube.h"

namespace Explorer
{
	void Cube::set(int slot, uint64_t cubie, uint64_t orient)
	{
		corners = (corners & ~(31LL << slot)) | (cubie << (slot+2) ) | (orient << slot);
	}

	Cube cube_ideal()
	{
		Cube ret;

		ret.corners = 0;
		ret.corners = ((uint64_t)(CUFR)<<(UFR+2)) +
				((uint64_t)(CURB)<<(URB+2)) +
				((uint64_t)(CUBL)<<(UBL+2)) +
				((uint64_t)(CULF)<<(ULF+2)) +

				((uint64_t)(CDRF)<<(DRF+2)) +
				((uint64_t)(CDFL)<<(DFL+2)) +
				((uint64_t)(CDLB)<<(DLB+2)) +
				((uint64_t)(CDBR)<<(DBR+2));

		return ret;
	}

	void cube_init()
	{
	}


	//int Cube_cmp(void *a, void *b)
	bool operator==(const Cube &a, const Cube &b)
	{
		return (a.corners == b.corners);
	}

	bool operator<(const Cube &a, const Cube &b)
	{
		return (a.corners < b.corners);
	}

	inline void cubie_cycle(uint64_t mask, uint64_t &corners, int a, int b, int c, int d)
	{
		uint64_t ca, cb, cc, cd;

		ca = corners & ((uint64_t)(mask)<<a); // Current state

		cb = corners & ((uint64_t)(mask)<<b);

		cc = corners & ((uint64_t)(mask)<<c);

		cd = corners & ((uint64_t)(mask)<<d);

		corners &= ~(((uint64_t)mask<<a) | ((uint64_t)mask<<b) | ((uint64_t)mask<<c) | ((uint64_t)mask<<d));


		corners |= (((ca)>>a)<<b);
		corners |= (((cb)>>b)<<c); 
		corners |= (((cc)>>c)<<d); 
		corners |= (((cd)>>d)<<a); 
	}

	inline void corner_cycle(uint64_t &corners, int a, int b, int c, int d)
	{
		cubie_cycle(31, corners, a, b, c, d);
	}

	Cube moveR(const Cube &state)
	{
		Cube c = state;

		// Corner orientation
		
		#define tmp1 (((uint64_t)1<<(UFR+1)) | ((uint64_t)1<<(URB+1)) | ((uint64_t)1<<(DBR+1)) | ((uint64_t)1<<(DRF+1)))
		
		c.corners ^= ((c.corners & tmp1)>>1)^(tmp1>>1);

	/*      Old code	
		if(!read(c.corners, UFR+1))
		{
			trig(c.corners, UFR);
		}
		if(!read(c.corners, URB+1))
		{
			trig(c.corners, URB);
		}
		if(!read(c.corners, DBR+1))
		{
			trig(c.corners, DBR);
		}
		if(!read(c.corners, DRF+1))
		{
			trig(c.corners, DRF);
		}

	*/

		//Corner Permutation
		corner_cycle(c.corners, UFR, URB, DBR, DRF);

		return c;
	}

	Cube moveRp(const Cube &state)
	{
		Cube c = state;
		c = moveR(c);
		c = moveR(c);
		c = moveR(c);

		return c;
	}

	Cube moveU(const Cube &state)
	{
		Cube c = state;
		//Corner orientation
		
		#define tmp_U (((uint64_t)1<<UFR) | ((uint64_t)1<<ULF) | ((uint64_t)1<<UBL) | ((uint64_t)1<<URB) )

		c.corners ^= (state.corners & (tmp_U)) | ((state.corners & (tmp_U))<<1);
		c.corners ^= (state.corners & (tmp_U<<1)) | ((state.corners & (tmp_U<<1))>>1);

		/* //Old code
		if((read(c.corners, UFR) || read(c.corners, UFR+1)))
		{
			trig(c.corners, UFR);
			trig(c.corners, UFR+1);
		}
		if((read(c.corners, ULF) || read(c.corners, ULF+1)))
		{
			trig(c.corners, ULF);
			trig(c.corners, ULF+1);
		}
		if((read(c.corners, UBL) || read(c.corners, UBL+1)))
		{
			trig(c.corners, UBL);
			trig(c.corners, UBL+1);
		}
		if((read(c.corners, URB) || read(c.corners, URB+1)))
		{
			trig(c.corners, URB);
			trig(c.corners, URB+1);
		
		}*/	
		

		//Corner Permutation
		corner_cycle(c.corners, UFR, ULF, UBL, URB);

		return c;
	}

	Cube moveUp(const Cube &state)
	{
		Cube c = state;
		c = moveU(c);
		c = moveU(c);
		c = moveU(c);

		return c;
	}

	Cube moveF(const Cube &state)
	{
		Cube c = state;
		//Corner orientation
		
		#define tmp_F (((uint64_t)1<<UFR) | ((uint64_t)1<<DRF) | ((uint64_t)1<<DFL) | ((uint64_t)1<<ULF) )

		c.corners ^= ( (~c.corners) & tmp_F )<<1;

		//Corner Permutation
		corner_cycle(c.corners, UFR, DRF, DFL, ULF);

		return c;
	}

	Cube moveFp(const Cube &state)
	{
		Cube c = state;
		c = moveF(c);
		c = moveF(c);
		c = moveF(c);

		return c;
	}

	Cube moveL(const Cube &state)
	{
		Cube c = state;

		// Corner orientation
		
		#define tmp_L (((uint64_t)1<<(ULF+1)) | ((uint64_t)1<<(DFL+1)) | ((uint64_t)1<<(DLB+1)) | ((uint64_t)1<<(UBL+1)))
		
		c.corners ^= ((c.corners & tmp_L)>>1)^(tmp_L>>1);

		//Corner Permutation
		corner_cycle(c.corners, ULF, DFL, DLB, UBL);

		return c;
	}

	Cube moveLp(const Cube &state)
	{
		Cube c = state;
		c = moveL(c);
		c = moveL(c);
		c = moveL(c);

		return c;
	}

	Cube moveD(const Cube &state)
	{
		Cube c = state;
		//Corner orientation
		
		#define tmp_D (((uint64_t)1<<DRF) | ((uint64_t)1<<DBR) | ((uint64_t)1<<DLB) | ((uint64_t)1<<DFL) )

		c.corners ^= (state.corners & (tmp_D)) | ((state.corners & (tmp_D))<<1);
		c.corners ^= (state.corners & (tmp_D<<1)) | ((state.corners & (tmp_D<<1))>>1);

		//Corner Permutation
		corner_cycle(c.corners, DRF, DBR, DLB, DFL);

		return c;
	}

	Cube moveDp(const Cube &state)
	{
		Cube c = state;
		c = moveD(c);
		c = moveD(c);
		c = moveD(c);

		return c;
	}

	Cube moveB(const Cube &state)
	{
		Cube c = state;
		//Corner orientation
		
		#define tmp_B (((uint64_t)1<<URB) | ((uint64_t)1<<UBL) | ((uint64_t)1<<DLB) | ((uint64_t)1<<DBR) )

		c.corners ^= ( (~c.corners) & tmp_B )<<1;

		//Corner Permutation
		corner_cycle(c.corners, URB, UBL, DLB, DBR);

		return c;
	}

	Cube moveBp(const Cube &state)
	{
		Cube c = state;
		c = moveB(c);
		c = moveB(c);
		c = moveB(c);

		return c;
	}

}

