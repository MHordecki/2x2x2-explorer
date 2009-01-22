
#include <iostream>

#include "Bfs.h"

namespace Explorer
{
	void BfsTraversal::traverse(Cube state, Examiner &examiner)
	{
		count = 0;
		allcount = 0;

		int move_num = moves.size();

		while(!Q.empty())
			Q.pop();

		V.clear();
		paths.clear();

		Q.push(make_pair(state.corners, make_pair(-1, -1)));

		while(!Q.empty())
		{
			Cube x;
			x.corners = Q.front().first;
			pair<int, char> previous = Q.front().second;
			Q.pop();

			++allcount;

			if(V.find(x.corners) != V.end())
				continue;

			V.insert(x.corners);
			paths.push_back(previous);
			++count;

			if(verbosity)
				if(count%100000 == 0) std::cout << count << " / " << allcount << std::endl;

			BfsTraversalCallback foo(x, moves, paths, paths.size() - 1);

			if(examiner(foo)) continue;

			for(int i = 0; i < move_num; i++)
			{
				Cube st = moves[i].fun(x);
				Q.push(make_pair(st.corners, make_pair(paths.size() - 1, i)));
			}
		}

		if(verbosity)
			std::cout << "TOTAL: " << V.size() << std::endl;
	}
		
}

