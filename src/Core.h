#ifndef _CORE_H
#define _CORE_H

#include <vector>
#include "222cube.h"

#define MASK_R 1
#define MASK_U 2
#define MASK_F 4
#define MASK_L 8
#define MASK_D 16
#define MASK_B 32

namespace Explorer
{
	Move MoveR, MoveRp;
	Move MoveU, MoveUp;
	Move MoveF, MoveFp;
	Move MoveL, MoveLp;
	Move MoveD, MoveDp;
	Move MoveB, MoveBp;

	void init();

	std::vector<std::pair<Move, Move> > &getRUFMoves();

	class Mask
	{
		protected:
			uint64_t bitmask;
			uint64_t goal;
		public:
			Mask(): bitmask(~0LL), goal(cube_ideal().corners) {}

			void maskCubie(int slot, bool masked, uint64_t cubie);
			void maskOrientation(int slot, bool masked, uint64_t orientation);

			void reset();

			bool operator==(const Cube &state);
	};

}
#endif
