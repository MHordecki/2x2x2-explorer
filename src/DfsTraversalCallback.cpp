
#include "DfsTraversalCallback.h"

namespace Explorer
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
