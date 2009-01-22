#ifndef _SEQUENCE_H
#define _SEQUENCE_H

#include <string>
#include <vector>

#include "222cube.h"

using std::vector;
using std::string;

namespace Explorer
{
	/**
	 * Sequence represents a certain move sequence.
	 */
	class Sequence
	{
		protected:
			vector<char> storage;
			const vector<Move> &moves;
		public:
			Sequence(const vector<Move> &_moves): moves(_moves) {}

			virtual int size() const;
			virtual const Move &operator[](int index) const;
			
			virtual void push(Move move);
			virtual const Move &pop();
			virtual void clear();

			//virtual ostream &operator<<(const ostream &);
			
			virtual int getQtmMetric() const;
			virtual int getHtmMetric() const;
			virtual string format() const;
	};
}

#endif
