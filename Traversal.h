#ifndef _TRAVERSAL_H
#define _TRAVERSAL_H

#include "222cube.h"
#include "Examiner.h"

namespace Brutha
{
	/**
	 * An abstract class for Traversal objects.
	 * These objects traverse through the whole 2x2x2
	 * state universe using a defined technique.
	 *
	 * Each of these states is then encapsulated in TraversalCallback
	 * and passed to Examiner object, which is user-provided.
	 *
	 * @see TraversalCallback
	 * @see Examiner
	 */
	class Traversal
	{
		public:
			/**
			 * Performs the traversal.
			 *
			 * @param state beginning state.
			 * @param examiner user-provided object which examines each visited state.
			 */
			virtual void traverse(Cube state, Examiner &examiner) = 0;
	};
}

#endif
