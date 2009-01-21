#include <iostream>
#include <ctime>
#include "222cube.h"
using namespace std;
#define LIMIT 50000000

typedef Cube (*move) (const Cube &);

void test(move func, Cube state, const char* title)
{
	int start = clock(), end;
	
	for(int i = 0; i < LIMIT; i++)
	{
		func(state);
	}

	end = clock();

	cout << title << ": " << double(end-start)/double(CLOCKS_PER_SEC) << endl;
}

int main()
{
	cout << "Testing with " << LIMIT << " iterations. " << endl;

	Cube c;

	test(moveR, c, "moveR");
	test(moveRp, c, "moveRp");
	test(moveL, c, "moveL");
	test(moveLp, c, "moveLp");
	test(moveU, c, "moveU");
	test(moveUp, c, "moveUp");
	test(moveD, c, "moveD");
	test(moveDp, c, "moveDp");
	test(moveF, c, "moveF");
	test(moveFp, c, "moveFp");
	test(moveB, c, "moveB");
	test(moveBp, c, "moveBp");
}
