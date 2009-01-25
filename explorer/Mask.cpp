#include "Mask.h"

namespace Explorer
{

	void Mask::maskCubie(int slot, bool masked, uint64_t cubie)
	{
		bitmask |= 28LL << slot; // 1'ing the bitmask
		goal &= ~(28LL << slot); // 0'ing the goal

		if(masked)
		{
			bitmask &= ~(28LL << slot);

			if(cubie & MASK_L)
			{
				bitmask |= 8 << slot;
				goal = 8 << slot;
			}
			if(cubie & MASK_R)
			{
				bitmask |= 8 << slot;
			}
			if(cubie & MASK_B)
			{
				bitmask |= 4 << slot;
				goal = 4 << slot;
			}
			if(cubie & MASK_F)
			{
				bitmask |= 4 << slot;
			}
			if(cubie & MASK_D)
			{
				bitmask |= 16 << slot;
				goal = 16 << slot;
			}
			if(cubie & MASK_U)
			{
				bitmask |= 16 << slot;
			}

		} else
		{
			goal |= cubie << (slot+2);
		}

	}

	void Mask::maskOrientation(int slot, bool masked, uint64_t cubie)
	{
		bitmask |= 3LL << slot;
		goal &= ~(3LL << slot);

		if(masked)
		{
			bitmask &= ~(3LL << slot);
		}  else
		{
			goal |= cubie << slot;
		}
	}

	void Mask::reset()
	{
		bitmask = ~0LL;
		goal = cube_ideal().corners;
	}

	bool Mask::operator==(const Cube &state)
	{
		return (goal & bitmask) == (state.corners & bitmask);
	}

	uint64_t Mask::getState()
	{
		return goal;
	}

	uint64_t Mask::getBitmask()
	{
		return bitmask;
	}

}
