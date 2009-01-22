
#include <sstream>
#include <algorithm>

using namespace std;

#include "ReverseSequence.h"
namespace Explorer
{
	const Move &ReverseSequence::operator[](int index) const
	{
		return moves[storage[size() - 1 - index]];
	}
}
