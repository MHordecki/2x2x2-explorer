
#include <sstream>
#include <algorithm>

using namespace std;

#include "Sequence.h"
namespace Brutha
{
	/**
	 * Returns a size of the underlying storage.
	 * For more apropriate measure of the number of moves in the sequence,
	 * use getQtmMetric and getHtmMetric.
	 *
	 * @see getHtmMetric
	 * @see getQtmMetric
	 */
	int Sequence::size() const
	{
		return storage.size();
	}

	/**
	 * Returns a Move object at the given position
	 */
	const Move &Sequence::operator[](int index) const
	{
		return moves[storage[index]];
	}

	void Sequence::push(Move move)
	{
		storage.push_back(move.index);
	}

	const Move &Sequence::pop()
	{
		const Move &m = moves[storage.back()];
		storage.pop_back();
		return m;
	}

	int Sequence::getQtmMetric() const
	{
		return this->size();
	}

	int Sequence::getHtmMetric() const
	{
		vector<char> moves(storage.begin(), storage.end());

		moves.erase(unique(moves.begin(), moves.end()), moves.end());

		return moves.size();
	}

	/**
	 * Formats a Sequence to a human-readable form.
	 *
	 * @return string representation.
	 */
	string Sequence::format() const
	{
		if(size() == 1)
		{
			return string(operator[](0).name);
		}

		stringstream ss;

		for(int i = 0; i < size(); i++)
			ss << ' ' << operator[](i).name;
		ss << "\n";

		int count = 1;
		int last = operator[](0).index;
		bool space = false;
		for(int i = 1; i < size(); i++)
		{
			if(operator[](i).index == last)
				++count;
			else
			{
				if(space)
					ss << ' ';

				space = true;

				if(count == 1)
				{
					ss << moves[last].name;
				} else
					ss << moves[last].name[0] << 2;

				count = 1;
				last = operator[](i).index;
			}
		}

		if(count == 1)
		{
			ss << ' ' << moves[last].name;
		} else
			ss << ' ' << moves[last].name[0] << 2;

		

		return ss.str();
	}

}
