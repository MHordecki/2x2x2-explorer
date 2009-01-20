#ifndef _DFS_H
#define _DFS_H_
#include "222cube.h"
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <iostream>
#include <unordered_set>

using std::vector;
using std::pair;
using std::set;
using std::queue;

//#define OMP_NESTED 0

class BFS
{
	protected:
	typedef bool (*Function)(const Cube &, const vector<char>&, const vector<Move> &);

		vector<Move> moves;
		vector<int> cancellations;

		queue<pair<uint64_t, pair<int, char> > > Q;
		unordered_set<uint64_t> V;
		vector<pair<int, char> > paths;

		int count;
		int allcount;


		void search(Function F, Cube state)
		{
			count = 0;
			allcount = 0;
			int move_num = moves.size();
			while(!Q.empty()) {Q.pop();}
			V.clear();
			paths.clear();

			Q.push(make_pair(state.corners, make_pair(-1, -1)));

			while(!Q.empty())
			{
				Cube x;
				x.corners = Q.front().first;
				pair<int, char> previous = Q.front().second;
				Q.pop();
				++allcount;

				if(V.find(x.corners) != V.end())
					continue;

				V.insert(x.corners);
				paths.push_back(previous);
				++count;

				if(count%100000 == 0) printf("%d / %d -> %.2f%%\n",count, allcount, double(count)/double(allcount)*100);

				/* Sequence reconstruction */
				
				vector<char> seq;
				int cur = paths.size() - 1;

				while(cur)
				{
					seq.push_back(paths[cur].second);
					cur = paths[cur].first;
				}

				if(F(x, seq, moves)) continue;

				for(int i = 0; i < move_num; i++)
				{
					Cube st = moves[i].fun(x);
					Q.push(make_pair(st.corners, make_pair(paths.size() - 1, i)));
				}
			}
		printf("TOTAL: %d\n", V.size());
		}



		

	public:
		BFS(vector<pair<Move, Move> > &moves): V(4000000)
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

			paths.reserve(4000000);

		}

		void execute(Cube start, Function F)
		{
			vector<char> seq;

			search(F, start);
		}

		

};

#endif

