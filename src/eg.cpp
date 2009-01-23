#include <iostream>
#include <vector>
#include "222Explorer.h"

using namespace std;
using namespace Explorer;

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

Mask foo;

/**
 * Our Examiner implementation.
 *
 * Checks whether the visited state is a solved state.
 * In such case it prints the solving algorithm.
 */
class MyExaminer: public Examiner
{
	public:
	virtual bool operator()(TraversalCallback &cb)
	{
		Cube c = cb.getState();
		uint64_t mask = ( (16LL << UFR) | (16LL << URB) | (16LL << UBL) | (16LL << ULF) | (31LL << DFL) | (31LL << DLB) | (31LL << DBR) | (31LL << DRF));

		Cube G = cube_ideal();
		G.set(DFL, CDBR, orientUD);
		G.set(DBR, CDFL, orientUD);

		uint64_t goal = G.corners;


		if((c.corners & mask) == ((goal & mask)))// | (orientFB << UFR) | (orientRL << URB) | (orientRL << ULF) ) )
		{
			const Sequence &sseq = cb.getSequence();

			vector<string> seq = sseq.getFormattedVector();

			bool space = false;

			for(vector<string>::iterator vi = seq.begin(); vi != seq.end(); ++vi)
			{
				if(space)
					cout << ' ';
				
				space = true;
				cout << *vi;
			}

			cout << endl;
	
		}

		return 0;
	}

};

int main()
{
	// Initialization
	init();

	BfsTraversal bfs(getRUFMoves());
	bfs.setVerbosity(false);

	// Creating simple situation to solve
	// Following line should work in a
	//Cube st = executeAlgorithm(cube_ideal(), "U' L' U2 L U L' U L R U2 R' U' R U' R' U"); <- 2x2x2 Explorer 1.0 ;)
	
	Cube st = cube_ideal();

	MyExaminer myexaminer;
	
	bfs.traverse(st, myexaminer);

	return 0;
}
