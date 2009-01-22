#ifndef _CORE_H
#define _CORE_H

#include <vector>
#include "222cube.h"

namespace Explorer
{
	void init();

	std::vector<std::pair<Move, Move> > &getRUFMoves();

}
#endif
