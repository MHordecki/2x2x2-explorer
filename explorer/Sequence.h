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

			/**
			 * Adds new move to the sequence.
			 */			
			virtual void push(Move move);

			/**
			 * Removes and returns the last move from the sequence.
			 */
			virtual const Move &pop();

			virtual void clear();

			//virtual ostream &operator<<(const ostream &);
			
			/**
			 * Returns a sequence length in the QTM metric.
			 */
			virtual int getQtmMetric() const;

			/**
			 * Returns a sequence length in the HTM metric.
			 */
			virtual int getHtmMetric() const;

			virtual vector<string> getFormattedVector() const;

			/**
			 * Formats the sequence in a human-readable way.
			 *
			 * Uses information stored in Move objects.
			 */
			virtual string format() const;
	};
}

#endif
