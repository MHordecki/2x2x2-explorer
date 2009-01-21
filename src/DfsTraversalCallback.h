#ifndef _DFSTRAVERSALCALLBACK_H
#define _DFSTRAVERSALCALLBACK_H

#include "222cube.h"

#include "TraversalCallback.h"
#include "Sequence.h"

namespace Brutha
{
	class DfsTraversalCallback: public TraversalCallback
	{
		protected:
			const Sequence &seq;
			Cube state;

		public:
			DfsTraversalCallback(Cube _state, Sequence &_seq): seq(_seq), state(_state) {}

			virtual Cube getState();
			virtual const Sequence &getSequence();
			virtual const Move &getParentMove();
	};
}
#endif
