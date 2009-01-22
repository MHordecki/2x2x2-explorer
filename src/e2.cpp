#include <iostream>
#include <vector>
#include "Explorer.h"

using namespace std;
using namespace Explorer;

/**
 * Our Examiner implementation.
 *
 * Checks whether the visited state is a solved state.
 * In such case it prints the solving algorithm.
 */

void strip(uint64_t x)
{
	int foo = 0;
	while(x)
	{
		if(x&1)
		{
			cout << 1;
		}
		else
			cout << 0;

		if(++foo % 5 == 0) cout << " | ";

		x /= 2;
	}

	cout << endl;
}

class MyExaminer: public Examiner
{
	protected:
		uint64_t mask;
		Cube goal;
	public:
	MyExaminer()
	{
		mask = ( (12LL << UFR) | (12LL << URB) | (12LL << UBL) | (12LL << ULF) | (12LL << DFL) | (12LL << DLB) | (12LL << DBR) | (12LL << DRF));
		strip(mask);
		mask = ~mask;
		goal = cube_ideal();
		strip(goal.corners);
		goal.corners &= mask;
		strip(goal.corners);
		cout << endl;
	}

	virtual bool operator()(TraversalCallback &cb)
	{
		Cube c = cb.getState();
		c.corners &= mask;

		if(c == goal)
		{
			const Sequence &seq = cb.getSequence();
			strip(cb.getState().corners);
			strip(c.corners);

			cout << seq.format() << "(" << seq.getQtmMetric() << "q, " << seq.getHtmMetric() << "h)" << endl;
		} 

		return 0;
	}

};

int main()
{
	// Initialization
	init();

	BfsTraversal bfs(getRUFMoves());

	// Creating simple situation to solve
	// Following line should work in a
	//Cube st = executeAlgorithm(cube_ideal(), "U' L' U2 L U L' U L R U2 R' U' R U' R' U"); <- 2x2x2 Explorer 1.0 ;)
	
	Cube st = cube_ideal();
	st.corners &= ~(31LL << URB);
	st.corners |= corner_compose(CURB, orientRL) << URB;

	st.corners &= ~(31LL << UBL);
	st.corners |= corner_compose(CUBL, orientRL) << UBL;

	MyExaminer myexaminer;
	
	bfs.traverse(st, myexaminer);

	return 0;
}
