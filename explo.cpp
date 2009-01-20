#include <iostream>
#include <vector>
using namespace std;

#include "222cube.h"
#include "explorer.h"

typedef Cube (*MovePtr)(const Cube&);
void strip(uint64_t);

using namespace Brutha;

class FooBar: public Examiner
{
	public:
	virtual bool operator()(TraversalCallback &cb)
	{
		Cube c = cb.getState();

		if(c == cube_ideal())
		{
			const Sequence &seq = cb.getSequence();

			cout << "FOUND " << seq.size() << endl;
			strip(c.corners);
			cout << seq.format() << endl;
		} 

		return 0;
	}
} foobar;

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
	strip(cube_ideal().corners);
	vector<pair<Move, Move> > moves;

	Move R = {moveR, "R"}, Rp = {moveRp, "Rp"};
	moves.push_back(MP(R, Rp));
	Move U = {moveU, "U"}, Up = {moveUp, "Up"};
	moves.push_back(MP(U, Up));
	Move F = {moveF, "F"}, Fp = {moveFp, "Fp"};
	moves.push_back(MP(F, Fp));

	//BFS foo(moves);
	cout << "Banho" << endl;
	DfsTraversal foo(moves);
	foo.setLimit(12);
	cout << "Pinho" << endl;

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
	
	
	cout << "Blut" << endl;
	Examiner &x = foobar;
	cout << "Blut" << endl;

	foo.traverse(st, x);

}
