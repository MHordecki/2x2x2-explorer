#include <iostream>
#include <cstdlib>
#include <cassert>
#include "222cube.h"
using namespace std;
typedef void (*testfun)();

void testR()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveR(a);

	assert(a.corners == cube_ideal().corners);
}
void testL()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveL(a);

	assert(a.corners == cube_ideal().corners);
}
void testU()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveU(a);

	assert(a.corners == cube_ideal().corners);
}
void testD()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveD(a);

	assert(a.corners == cube_ideal().corners);
}
void testF()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveF(a);

	assert(a.corners == cube_ideal().corners);
}
void testB()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveB(a);

	assert(a.corners == cube_ideal().corners);
}
void testRp()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveRp(a);

	assert(a.corners == cube_ideal().corners);
}
void testLp()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveLp(a);

	assert(a.corners == cube_ideal().corners);
}
void testUp()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveUp(a);

	assert(a.corners == cube_ideal().corners);
}
void testDp()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveDp(a);

	assert(a.corners == cube_ideal().corners);
}
void testFp()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveFp(a);

	assert(a.corners == cube_ideal().corners);
}
void testBp()
{
	Cube a = cube_ideal();
	
	for(int i = 0; i < 4; i++) a = moveBp(a);

	assert(a.corners == cube_ideal().corners);
}

void testRD()
{
	Cube i = cube_ideal();
	Cube a = cube_ideal();
	
	for(int i = 0; i < 6; i++)
	{
	a = moveRp(a);
	a = moveDp(a);
	a = moveR(a);
	a = moveD(a);
	}

	assert(a.corners == i.corners);
}

void testLU()
{
	Cube i = cube_ideal();
	Cube a = cube_ideal();
	
	for(int i = 0; i < 6; i++)
	{
	a = moveLp(a);
	a = moveUp(a);
	a = moveL(a);
	a = moveU(a);
	}

	assert(a.corners == i.corners);
}
void testRU()
{
	Cube i = cube_ideal();
	Cube a = cube_ideal();
	
	for(int i = 0; i < 6; i++)
	{
	a = moveR(a);
	a = moveU(a);
	a = moveRp(a);
	a = moveUp(a);
	}

	assert(a.corners == i.corners);
}
void testRF()
{
	Cube i = cube_ideal();
	Cube a = cube_ideal();
	
	for(int i = 0; i < 6; i++)
	{
	a = moveRp(a);
	a = moveFp(a);
	a = moveR(a);
	a = moveF(a);
	}

	assert(a.corners == i.corners);
}
void testRB()
{
	Cube i = cube_ideal();
	Cube a = cube_ideal();
	
	for(int i = 0; i < 6; i++)
	{
	a = moveR(a);
	a = moveB(a);
	a = moveRp(a);
	a = moveBp(a);
	}

	assert(a.corners == i.corners);
}
void testRUsmash()
{
	Cube i = cube_ideal();
	Cube a = cube_ideal();
	
	for(int i = 0; i < 6; i++)
	{
	a = moveRp(a);
	a = moveU(a);
	a = moveR(a);
	a = moveUp(a);
	}

	assert(a.corners == i.corners);
}


void _test(testfun f, const char *txt)
{
	cout << txt << ": ";
	f();
	cout << "OK" << endl;
}
int main()
{

	cout << "Testing..." << endl;
	
	cout << "\nSingle moves\n" << endl;

	_test(testR, "testR");
	_test(testRp, "testRp");
	_test(testU, "testU");
	_test(testUp, "testUp");
	_test(testL, "testL");
	_test(testLp, "testLp");
	_test(testD, "testD");
	_test(testDp, "testDp");
	_test(testF, "testF");
	_test(testFp, "testFp");
	_test(testB, "testB");
	_test(testBp, "testBp");

	cout << "\nSimple integration\n" << endl;

	_test(testRU, "testRU");
	_test(testRUsmash, "testRUsmash");
	_test(testLU, "testLU");
	_test(testRD, "testRD");
	_test(testRF, "testRF");
	_test(testRB, "testRB");
}
