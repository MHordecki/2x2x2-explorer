#ifndef _DFS_H
#define _DFS_H

#include <vector>
using std::vector;
using std::pair;

#include "222cube.h"
#include "Traversal.h"
#include "Examiner.h"
#include "DfsTraversalCallback.h"
#include "Sequence.h"

namespace Explorer
{
	class DfsTraversal : public Traversal
	{
		protected:
			int limit;
			int counter;

			void search(Examiner &examiner, Cube state, Sequence &seq, int, int, int, int);

		public:
			DfsTraversal(vector<pair<Move, Move> > &_moves, int _limit = 0): Traversal(_moves), limit(_limit)
			{
			}

			virtual int getLimit();

			virtual void setLimit(int limit);

			virtual void traverse(Cube start, Examiner &examiner);

	};

}

#endif

