/*
* Header file for AI functions
*/

#ifndef AI_H_
#define AI_H_

#include "stdafx.h"
#include "DraughtsModule.h"
#include "Heuristic.h"
#include "Debug.h"
#include <stdlib.h>
#include <time.h>
#include <string>

const int SEARCH_DEPTH = 4;
const bool N_MAX = true;
const bool N_MIN = false;

//Returns the heuristic desirability value for the board state
//double heuristic(Board);

//Heuristic parameter coefficients (arbitrary)
const double PARAM_MULT[PARAM_TOTAL] = {
	1.00391,
	34,
	1.25,
	2.125,
	48.3164,
	51.5156,
	0,
	56.5,
	14
};

class AI {
	protected:
		cellState colour;
		int direction;
		int searchDepth;
		Heuristic heuristic;
		Debug debug;

	public:
		AI();
		AI(cellState playercolour);
		AI(cellState playercolour, Heuristic heur);
		cellState getColour();
		void setSearchDepth(int depth);
		int getSearchDepth();

		//Returns a vector containing all legal moves on board
		std::vector<MoveSequence> getAvailableMoves(Board);

		void gatherCaptures(Board board, DraughtsMove currentmove, std::vector<MoveSequence>&);

		//Returns a list of available captures to the piece at Cell on Board
		std::vector<MoveSequence> getAvailableCapturesFromPoint(Board,Cell);

		//Returns what the AI thinks is the optimal move given the board state
		virtual MoveSequence getMove(Board, int depth, bool nodeType = N_MAX, double a = -100000000, double b = 100000000);

		void switchTeam();
};

#endif

