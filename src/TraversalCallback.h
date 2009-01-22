#ifndef _TRAVERSALCALLBACK_H
#define _TRAVERSALCALLBACK_H

#include <vector>

#include "222cube.h"
#include "Sequence.h"

namespace Explorer
{
	/**
	 * An abstract class for information chunks that are given to
	 * Examiner objects by TraveRsal objects.
	 *
	 * @see Traversal
	 * @see Examiner
	 */
	class TraversalCallback
	{
		public:
			/**
			 * Returns current cube state.A
			 *
			 * @return Puzzle state.
			 */
			virtual Cube getState() = 0;

			/**
			 * Returns a sequence of moves that leads from the traversal beginning state 
			 * to the current one.
			 *
			 * @note This operation can be time consuming, depending on the
			 * travelsal technique. Use it sparingly.
			 *
			 * @return a Sequence object.
			 *
			 * @see getState
			 * @see Sequence
			 */
			virtual const Sequence &getSequence() = 0;

			virtual const Move &getParentMove() = 0;
	};
};
#endif
