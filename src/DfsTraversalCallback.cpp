
#include "DfsTraversalCallback.h"

namespace Brutha
{
	Cube DfsTraversalCallback::getState()
	{
		return state;
	}

	const Sequence &DfsTraversalCallback::getSequence()
	{
		return seq;
	}

	const Move &DfsTraversalCallback::getParentMove()
	{
		return seq[seq.size() - 1];
	}
}
