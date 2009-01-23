
#include <sstream>
#include <algorithm>

using namespace std;

#include "Sequence.h"
namespace Explorer
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
	
	void Sequence::clear()
	{
		storage.clear();
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
		vector<string> seq = getFormattedVector();

		stringstream ss;
		bool space = false;

		for(vector<string>::iterator vi = seq.begin(); vi != seq.end(); ++vi)
		{
			if(space)
				ss << ' ';
			
			space = true;
			ss << *vi;
		}

		return ss.str();
	}
	
	vector<string> Sequence::getFormattedVector() const
	{
		if(size() == 0)
			return vector<string>();
		if(size() == 1)
		{
			vector<string> ret;
			ret.push_back(string(operator[](0).name));
			return ret;
		}

		vector<string> ret;
		ret.push_back(string());

		int count = 1;
		int last = operator[](0).index;

		for(int i = 1; i < size(); i++)
		{
			if(operator[](i).index == last)
				++count;
			else
			{
				if(count == 1)
				{
					ret.back().append(moves[last].name);
				} else if(count == 2)
				{
					ret.back().push_back(moves[last].name[0]);
				       	ret.back().push_back('2');
				}
				else
				{
					ret.back().push_back(moves[last].name[0]);
				       	ret.back().push_back('_');
				}

				count = 1;
				last = operator[](i).index;
				ret.push_back(string());
			}
		}

		if(count == 1)
		{
			ret.back().append(moves[last].name);
		} else if(count == 2)
		{
			ret.back().push_back(moves[last].name[0]);
			ret.back().push_back('2');
		}
		else
		{
			ret.back().push_back(moves[last].name[0]);
			ret.back().push_back('_');
		}

		

		return ret;
	}

}
