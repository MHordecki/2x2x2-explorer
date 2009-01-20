#include "Sequence.h"

namespace Brutha
{
	int Sequence::size() const
	{
		return storage.size();
	}

	const Move &Sequence::operator[](int index) const
	{
		return moves[storage[index]];
	}

	void Sequence::push(Move &move)
	{
		storage.push_back(move.index);
	}

	const Move &Sequence::pop()
	{
		const Move &m = moves[storage.back()];
		storage.pop_back();
		return m;
	}

	string Sequence::format() const
	{
		return string("HAHA");
	}

}
