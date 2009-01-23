
#include "Core.h"

namespace Explorer
{
	Move MoveR, MoveRp;
	Move MoveU, MoveUp;
	Move MoveF, MoveFp;
	Move MoveL, MoveLp;
	Move MoveD, MoveDp;
	Move MoveB, MoveBp;
	std::vector<std::pair<Move, Move> > RUFMoves;

	void init()
	{
		MoveR.fun = moveR;
		MoveR.name = "R";
		MoveRp.fun = moveRp;
		MoveRp.name = "R'";

		MoveU.fun = moveU;
		MoveU.name = "U";
		MoveUp.fun = moveUp;
		MoveUp.name = "U'";

		MoveF.fun = moveF;
		MoveF.name = "F";
		MoveFp.fun = moveFp;
		MoveFp.name = "F'";

		MoveL.fun = moveL;
		MoveL.name = "L";
		MoveLp.fun = moveLp;
		MoveLp.name = "L'";

		MoveD.fun = moveD;
		MoveD.name = "D";
		MoveDp.fun = moveDp;
		MoveDp.name = "D'";

		MoveB.fun = moveB;
		MoveB.name = "B";
		MoveBp.fun = moveBp;
		MoveBp.name = "B'";

		RUFMoves.push_back(std::make_pair(MoveR, MoveRp));
		RUFMoves.push_back(std::make_pair(MoveU, MoveUp));
		RUFMoves.push_back(std::make_pair(MoveF, MoveFp));
	}

	std::vector<std::pair<Move, Move> > &getRUFMoves()
	{
		return RUFMoves;
	}

	void Mask::maskCubie(int slot, bool masked, uint64_t cubie)
	{
		bitmask |= 28LL << slot;
		goal &= ~(28LL << slot);

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

}
