#ifndef _BFS_H
#define _BFS_H_

#include <unordered_set>
#include <queue>
#include <vector>

#include "222cube.h"
#include "Examiner.h"
#include "Traversal.h"
#include "BfsTraversalCallback.h"

using std::unordered_set;
using std::queue;
using std::vector;
using std::make_pair;
using std::pair;

namespace Explorer
{
	/**
	 * BfsTraversal implements a well-known BFS (Breadth-First Search) algorithm
	 * to traverse through 2x2x2 states.
	 *
	 * It visits each state only once - it therefore generates much less
	 * sequences than :class:`DfsTraversal`. It guarantees, hovewer, it's the
	 * shortest solution possible for the given state.
	 */
	class BfsTraversal: public Traversal
	{
		protected:

			/// To-be-visited states.
			queue<pair<uint64_t, pair<int, char> > > Q;

			// Set of the visited states.
			unordered_set<uint64_t> V;

			// State tree.
			vector<pair<int, char> > paths;

			// Size of V
			int count;

			// All states visited.
			int allcount;

		public:
			BfsTraversal(const vector<pair<Move, Move> > &_moves):  Traversal(_moves), V(4000000)
			{
				paths.reserve(4000000);
			}

			virtual void traverse(Cube start, Examiner &examiner);
	};

}

#endif

