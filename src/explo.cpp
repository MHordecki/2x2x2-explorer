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
class MyExaminer: public Examiner
{
	public:
	virtual bool operator()(TraversalCallback &cb)
	{
		Cube c = cb.getState();

		if(c == cube_ideal())
		{
			const Sequence &seq = cb.getSequence();

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
	st.corners &= ~(32LL << URB);
	st.corners |= corner_compose(CURB, orientRL) << URB;

	st.corners &= ~(32LL << UBL);
	st.corners |= corner_compose(CUBL, orientRL) << UBL;

	MyExaminer myexaminer;
	
	bfs.traverse(st, myexaminer);

	return 0;
}
