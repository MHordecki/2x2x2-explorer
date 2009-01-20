#ifndef _BFSTRAVERSALCALLBACK_H
#define _BFSTRAVERSALCALLBACK_H

#include <vector>

using std::vector;
using std::pair;

#include "222cube.h"

#include "TraversalCallback.h"
#include "Sequence.h"

namespace Brutha
{
	class BfsTraversalCallback: public TraversalCallback
	{
		protected:
			const vector<pair<int, char> > &paths;
			const vector<Move> &moves;
			Cube state;
			int index;
			Sequence seq;
			bool seq_processed;

		public:
			BfsTraversalCallback(Cube _state, const vector<Move> &_moves, const vector<pair<int, char> > &_paths, int _index): moves(_moves), paths(_paths), state(_state), index(_index), seq(_moves), seq_processed(false) {}

			virtual Cube getState();
			virtual const Sequence &getSequence();
			virtual const Move &getParentMove();
	};
}
#endif
