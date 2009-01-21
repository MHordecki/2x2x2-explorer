#ifndef _TRAVERSAL_H
#define _TRAVERSAL_H

#include "222cube.h"
#include "Examiner.h"

#include <vector>

namespace Brutha
{
	/**
	 * An abstract class for Traversal objects.
	 * These objects traverse through the whole 2x2x2
	 * state universe using a defined technique.
	 *
	 * Each of these states is then encapsulated in TraversalCallback
	 * and passed to Examiner object, which is user-provided.
	 *
	 * @see TraversalCallback
	 * @see Examiner
	 */
	class Traversal
	{
		protected:
			bool verbosity;
			std::vector<Move> moves;
			std::vector<int> cancellations;

		public:
			Traversal(std::vector<std::pair<Move, Move> > &_moves): cancellations(_moves.size() * 2, -1)
			{
				for(std::vector<std::pair<Move, Move> >::iterator it = _moves.begin(); it != _moves.end(); ++it)
				{
					if(it->first.fun)
					{
						this->moves.push_back(it->first);
						this->moves.back().index = this->moves.size() - 1;
					}
					if(it->second.fun)
					{
						this->moves.push_back(it->second);
						this->cancellations[this->moves.size()-1] = this->moves.size()-2;
						this->cancellations[this->moves.size()-2] = this->moves.size()-1;
						this->moves.back().index = this->moves.size() - 1;
					}
				}

			}

			/**
			 * Performs the traversal.
			 *
			 * @param state beginning state.
			 * @param examiner user-provided object which examines each visited state.
			 */
			virtual void traverse(Cube state, Examiner &examiner) = 0;
			virtual void setVerbosity(bool);
	};
}

#endif
