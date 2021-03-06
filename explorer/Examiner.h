#ifndef _EXAMINER_H
#define _EXAMINER_H

#include "Traversal/TraversalCallback.h"

namespace Explorer
{
	/**
	 * An abstract class from which each examiner object must inherit.
	 *
	 * Examiners are used to process cube states that are generated by
	 * Traversal objects.
	 *
	 * @see Traversal
	 */
	class Examiner
	{
		public:
			virtual bool operator()(TraversalCallback &) = 0;
	};
}

#endif
