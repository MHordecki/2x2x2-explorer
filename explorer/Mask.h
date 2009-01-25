#ifndef _MASK_H
#define _MASK_H

#include "222cube.h"

#define MASK_ANY 0
#define MASK_R 1
#define MASK_U 2
#define MASK_F 4
#define MASK_L 8
#define MASK_D 16
#define MASK_B 32

namespace Explorer
{
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

			uint64_t getBitmask();
			uint64_t getState();
	};

}
#endif
