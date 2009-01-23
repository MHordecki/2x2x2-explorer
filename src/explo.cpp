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

			strip(c.corners);
			string seq.format();
			vector<string> foo;
			
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
	bfs.setVerbosity(true);

	// Creating simple situation to solve
	// Following line should work in a
	//Cube st = executeAlgorithm(cube_ideal(), "U' L' U2 L U L' U L R U2 R' U' R U' R' U"); <- 2x2x2 Explorer 1.0 ;)
	
	Cube st = cube_ideal();
	st.set(URB, CURB, orientRL);
	st.set(UBL, CUBL, orientRL);

	MyExaminer myexaminer;
	
	bfs.traverse(st, myexaminer);

	return 0;
}
