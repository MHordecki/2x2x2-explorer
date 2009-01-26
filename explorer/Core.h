#ifndef _CORE_H
#define _CORE_H

#include <vector>
#include "222cube.h"

namespace Explorer
{
	extern Move MoveR, MoveRp;
	extern Move MoveU, MoveUp;
	extern Move MoveF, MoveFp;
	extern Move MoveL, MoveLp;
	extern Move MoveD, MoveDp;
	extern Move MoveB, MoveBp;

	/**
	 * Inits the 2x2x2 Explorer.
	 *
	 * @warning Call this before any other call to the 2x2x2
	 * Explorer.
	 */
	void init();

	/**
	 * Returns a pre-build vector of six moves (R, R', U, U', F, F'). Useful
	 * for passing it straight into traversal objects.
	 */
	const std::vector<std::pair<Move, Move> > &getRUFMoves();

}
#endif
