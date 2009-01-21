
#include "BfsTraversalCallback.h"
#include <iostream>
using namespace std;
namespace Brutha
{
	Cube BfsTraversalCallback::getState()
	{
		return state;
	}

	const Sequence &BfsTraversalCallback::getSequence()
	{
		if(seq_processed)
			return seq;

		seq.clear();

		int cur = index;
		while(cur)
		{
			//cout << int(paths[cur].first) << " -> " << int(paths[cur].second) << " " << moves[paths[cur].second].name << endl;
			seq.push(moves[paths[cur].second]);
			cur = paths[cur].first;
		}
		
		seq_processed = true;

		//cout << seq.size() << endl;
				
		return seq;
	}

	const Move &BfsTraversalCallback::getParentMove()
	{
		return moves[paths[index].second];
	}
}
