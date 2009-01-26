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
	extern Move MoveR, MoveRp;
	extern Move MoveU, MoveUp;
	extern Move MoveF, MoveFp;
	extern Move MoveL, MoveLp;
	extern Move MoveD, MoveDp;
	extern Move MoveB, MoveBp;

	void init();

	const std::vector<std::pair<Move, Move> > &getRUFMoves();

	void strip(uint64_t);
	void strip(Cube &);

}
#endif
