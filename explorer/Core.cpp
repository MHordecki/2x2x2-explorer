
#include "Core.h"
#include <iostream>

using std::cout;
using std::endl;
namespace Explorer
{
	Move MoveR, MoveRp;
	Move MoveU, MoveUp;
	Move MoveF, MoveFp;
	Move MoveL, MoveLp;
	Move MoveD, MoveDp;
	Move MoveB, MoveBp;
	std::vector<std::pair<Move, Move> > RUFMoves;

	void init()
	{
		MoveR.fun = moveR;
		MoveR.name = "R";
		MoveRp.fun = moveRp;
		MoveRp.name = "R'";

		MoveU.fun = moveU;
		MoveU.name = "U";
		MoveUp.fun = moveUp;
		MoveUp.name = "U'";

		MoveF.fun = moveF;
		MoveF.name = "F";
		MoveFp.fun = moveFp;
		MoveFp.name = "F'";

		MoveL.fun = moveL;
		MoveL.name = "L";
		MoveLp.fun = moveLp;
		MoveLp.name = "L'";

		MoveD.fun = moveD;
		MoveD.name = "D";
		MoveDp.fun = moveDp;
		MoveDp.name = "D'";

		MoveB.fun = moveB;
		MoveB.name = "B";
		MoveBp.fun = moveBp;
		MoveBp.name = "B'";

		RUFMoves.push_back(std::make_pair(MoveR, MoveRp));
		RUFMoves.push_back(std::make_pair(MoveU, MoveUp));
		RUFMoves.push_back(std::make_pair(MoveF, MoveFp));
	}

	std::vector<std::pair<Move, Move> > &getRUFMoves()
	{
		return RUFMoves;
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

	void strip(Cube &c)
	{
		strip(c.corners);
	}

}
