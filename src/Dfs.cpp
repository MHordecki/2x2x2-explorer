
#include <iostream>

#include "Dfs.h"

namespace Brutha
{
	int DfsTraversal::getLimit() 
	{
		return limit;
	}

	void DfsTraversal::setLimit(int limit)
	{
		this->limit = limit;
	}

	void DfsTraversal::traverse(Cube start, Examiner &examiner)
	{
		counter = 0;
		Sequence seq(moves);

		search(examiner, start, seq, limit, -1, -1, 0);
	}

	void DfsTraversal::search(Examiner &examiner, Cube state, Sequence &seq, int level, int ommit, int lastmove, int count)
	{
		DfsTraversalCallback foo(state, seq);
		if(examiner(foo)) return;

		if(level <= 0) return;

		int move_num = this->moves.size();

		++counter;
		
		if(verbosity)
			if(counter%100000==0) std::cout << counter << std::endl;

		for(int i = 0; i < move_num; i++)
		{
			if(i == ommit || (i == lastmove && count > 1))
				continue;

			seq.push(moves[i]);
			Cube st = moves[i].fun(state);

			if(i == lastmove)
				search(examiner, st, seq, level - 1, cancellations[i], i, count + 1);
			else
				search(examiner, st, seq, level - 1, cancellations[i], i, 1);

			seq.pop();
		}
	}

}
