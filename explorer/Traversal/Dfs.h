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
	/**
	 * :class:`DfsTraversal` uses a well-known DFS (Depth-First Search) algorithm
	 * to traverse through 2x2x2 states It's a lot slower than it's counterpart,
	 * :class:`BfsTraversal`, but it visits states multiple times, each time with
	 * a *different* Sequence leading to it. It can be therefore used to generate
	 * many algorithms solving single state.
	 *
	 * :class:`DfsTraversal` needs one parameter to function - the recursion limit.
	 * It specifies how deep the algorithm will search, and effectively the maximal
	 * length of sequences returned.
	 */
	class DfsTraversal : public Traversal
	{
		protected:
			int limit;
			int counter;

			void search(Examiner &examiner, Cube state, Sequence &seq, int, int, int, int);

		public:
		    
			/**
			 * This is a standard :func:`Traversal.Traversal` constructor
			 * with one optional parameter added (the recursion limit).
			 */
			DfsTraversal(const vector<pair<Move, Move> > &_moves, int _limit = 0): Traversal(_moves), limit(_limit)
			{
			}

			virtual int getLimit();

			virtual void setLimit(int limit);

			virtual void traverse(Cube start, Examiner &examiner);

	};

}

#endif

