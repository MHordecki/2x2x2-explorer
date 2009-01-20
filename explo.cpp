#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <set>
using namespace std;

#include "222cube.h"
#include "explorer.h"

typedef Cube (*MovePtr)(const Cube&);
void strip(uint64_t);

bool checker(const Cube &c, const vector<char> &seq, const vector<Move> &moves)
{
	if(c == cube_ideal())
	{
		cout << "FOUND " << seq.size() << endl;
		strip(c.corners);
		//cout << c.corners << endl << cube_ideal().corners << endl;
		int num = seq.size();
		for(int i = 0; i < num; i++)
		{
			printf("%s ", moves[seq[i]].name);
		}

		printf("\n");
	} 

	return 0;
}
void strip(uint64_t x)
{
	int i = 0;
	while(x)
	{
		i++;
		if(x&1)
			cout <<"1";
		else
			cout <<"0";

		if(i%5==0) cout << " | ";

		x /= 2;
	}
	cout << endl;

}
#define MP make_pair
int main()
{
	cube_init();
	strip(cube_ideal().corners);
	vector<pair<Move, Move> > moves;

	Move R = {moveR, "R"}, Rp = {moveRp, "Rp"};
	moves.push_back(MP(R, Rp));
	Move U = {moveU, "U"}, Up = {moveUp, "Up"};
	moves.push_back(MP(U, Up));
	//Move L = {moveL, "L"}, Lp = {moveLp, "Lp"};
	//moves.push_back(MP(L, Lp));
	//Move D = {moveD, "D"}, Dp = {moveDp, "Dp"};
	//moves.push_back(MP(D, Dp));
	Move F = {moveF, "F"}, Fp = {moveFp, "Fp"};
	moves.push_back(MP(F, Fp));

	BFS foo(moves);
	//DFS foo(moves);
	//foo.set_limit(12);

	Cube st = cube_ideal();

	st = moveUp(st);

	st = moveLp(st);
	st = moveU(st);
	st = moveU(st);
	st = moveL(st);
	st = moveU(st);
	st = moveLp(st);
	st = moveU(st);
	st = moveL(st);

	st = moveR(st);
	st = moveU(st);
	st = moveU(st);
	st = moveRp(st);
	st = moveUp(st);
	st = moveR(st);
	st = moveUp(st);
	st = moveRp(st);
	st = moveU(st);
	//st = moveU(st);
	//st = moveR(st);
	//st = moveU(st);
	//st = moveR(st);
	//st = moveR(st);
	//st = moveU(st);
	//st = moveRp(st);
	//st = moveU(st);
	//st = moveU(st);

	//foo.set_limit(5);

	foo.execute(st, checker);

}
