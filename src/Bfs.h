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

namespace Brutha
{
	class BfsTraversal: public Traversal
	{
		protected:

			vector<Move> moves;
			vector<int> cancellations;

			queue<pair<uint64_t, pair<int, char> > > Q;
			unordered_set<uint64_t> V;
			vector<pair<int, char> > paths;

			int count;
			int allcount;

		public:
			BfsTraversal(vector<pair<Move, Move> > &_moves): V(4000000), Traversal(_moves)
			{
				paths.reserve(4000000);
			}

			virtual void traverse(Cube start, Examiner &examiner);
	};

}

#endif

