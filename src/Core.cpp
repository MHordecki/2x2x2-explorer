
#include "Core.h"

namespace Explorer
{
	std::vector<std::pair<Move, Move> > RUFMoves;

	void init()
	{
		Move MoveR = {moveR, "R"};
		Move MoveRp = {moveRp, "R'"};

		Move MoveU = {moveU, "U"};
		Move MoveUp = {moveUp, "U'"};

		Move MoveF = {moveF, "F"};
		Move MoveFp = {moveFp, "F'"};

		RUFMoves.push_back(std::make_pair(MoveR, MoveRp));
		RUFMoves.push_back(std::make_pair(MoveU, MoveUp));
		RUFMoves.push_back(std::make_pair(MoveF, MoveFp));
	}

	std::vector<std::pair<Move, Move> > &getRUFMoves()
	{
		return RUFMoves;
	}
}
