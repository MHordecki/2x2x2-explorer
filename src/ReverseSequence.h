#ifndef _REVERSESEQUENCE_H
#define _REVERSESEQUENCE_H

#include <string>
#include <vector>

#include "222cube.h"
#include "Sequence.h"

using std::vector;
using std::string;

namespace Brutha
{
	/**
	 * Some of traversal techniques create sequences
	 * on demand, by using backtracking. They, therefore,
	 * produce 'reverse' sequences.
	 *
	 * This is moment when the ReverseSequence comes to play.
	 */
	class ReverseSequence: public Sequence
	{
		public:
			ReverseSequence(const vector<Move> &_moves): Sequence(_moves) {}
			virtual const Move &operator[](int index) const;
	};
}

#endif
