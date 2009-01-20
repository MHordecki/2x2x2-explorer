
#include "BfsTraversalCallback.h"

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

		int cur = index;
		while(cur)
		{
			seq.push(Move(moves[paths[cur].second]));
			cur = paths[cur].first;
		}
		
		seq_processed = true;
				
		return seq;
	}

	const Move &BfsTraversalCallback::getParentMove()
	{
		return moves[paths[index].second];
	}
}
