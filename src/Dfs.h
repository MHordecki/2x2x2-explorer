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

namespace Brutha
{
	class DfsTraversal : public Traversal
	{
		protected:
			vector<Move> moves;
			vector<int> cancellations;

			int limit;
			int counter;

			void search(Examiner &examiner, Cube state, Sequence &seq, int, int, int, int);

		public:
			DfsTraversal(vector<pair<Move, Move> > &_moves): cancellations(_moves.size() * 2, -1), limit(0)
			{
				for(vector<pair<Move, Move> >::iterator it = _moves.begin(); it != _moves.end(); ++it)
				{
					if(it->first.fun)
					{
						this->moves.push_back(it->first);
						this->moves.back().index = this->moves.size() - 1;
					}
					if(it->second.fun)
					{
						this->moves.push_back(it->second);
						this->cancellations[this->moves.size()-1] = this->moves.size()-2;
						this->cancellations[this->moves.size()-2] = this->moves.size()-1;
						this->moves.back().index = this->moves.size() - 1;
					}
				}
			}

			virtual int getLimit();

			virtual void setLimit(int limit);

			virtual void traverse(Cube start, Examiner &examiner);

	};

}

#endif

