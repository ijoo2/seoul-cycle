#pragma once

#include "board.h"

struct Move { unsigned char to, from, piece, color, capturedPiece; };

class Position
{
	public:
		/** TODO: Write constructors
		    might be useful to copy positions directly. **/
		void makeMove(Move const & m);
		void unmakeMove(Move const & m);
	private:
		void init();

		unsigned int ply;
		bool whiteCanCastle, blackCanCastle;

		Board positionBoards[14]; // (piecetypes + enpassants) * 2 
		Board attackBoards[14];
		Board moveBoards[14];
		
		Board colorBoards[2]; // W = 0, B = 1
		Board emptySquares;
		Board occupiedSquares;
};