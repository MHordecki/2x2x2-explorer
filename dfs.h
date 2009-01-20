#ifndef _DFS_H
#define _DFS_H_
#include "222cube.h"
#include <vector>
#include <vector>
using std::vector;
using std::pair;

using std::vector;

//#define OMP_NESTED 0

class DFS
{
	private:
	typedef bool (*Function)(const Cube &, const vector<char>&, const vector<Move> &);

	protected:
		vector<Move> moves;
		vector<int> cancellations;

		int limit;
		int counter;

		void search(Function F, Cube state, vector<char> &seq, int level, int ommit, int lastmove, int count)
		{
			if(F(state, seq, moves)) return;

			if(level <= 0) return;
			int move_num = moves.size();
			++counter;
			if(counter%100000==0) printf("%d\n", counter);

			//#pragma omp parallel for
			for(int i = 0; i < move_num; i++)
			{
				if(i == ommit || (i == lastmove && count > 1))
					continue;

				seq.push_back(i);
				Cube st = moves[i].fun(state);
				if(i == lastmove)
					search(F, st, seq, level - 1, cancellations[i], i, count + 1);
				else
					search(F, st, seq, level - 1, cancellations[i], i, 1);
				seq.pop_back();
			}
		}


		

	public:
		DFS(vector<pair<Move, Move> > &moves)
		{
			this->cancellations.assign(moves.size() * 2, -1);

			for(vector<pair<Move, Move> >::iterator it = moves.begin(); it != moves.end(); ++it)
			{
				if(it->first.fun)
					this->moves.push_back(it->first);
				if(it->second.fun)
				{
					this->moves.push_back(it->second);
					this->cancellations[this->moves.size()-1] = this->moves.size()-2;
					this->cancellations[this->moves.size()-2] = this->moves.size()-1;
				}
			}

			this->limit = 0;
		}

		int get_limit()
		{
			return this->limit;
		}

		void set_limit(int limit)
		{
			this->limit = limit;
		}

		void execute(Cube start, Function F)
		{
			counter = 0;
			vector<char> seq;

			search(F, start, seq, limit, -1, -1, 0);
		}

		

};

#endif

