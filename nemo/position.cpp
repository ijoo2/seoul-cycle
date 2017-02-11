#include "position.h"

void Position::makeMove(Move const & m)
{
	data_t fromToBoard;
	bool quiet;
	
	quiet = (m.capturedPiece != NULL);
	fromToBoard = (a1 << m.from) ^ (a1 << m.to);
	
	this->positionBoards[m.piece] ^= fromToBoard; // Update the piece's bit board.
	this->colorBoards[m.color] ^= fromToBoard; // Update the color's bit board.
	if (!quiet)
	{
		this->positionBoards[m.capturedPiece] ^= fromToBoard; // Update the captured piece's bit board.
		this->colorBoards[~m.color] ^= fromToBoard; // Update the captured color's bit board.
	}
	this->occupiedSquares ^= fromToBoard; // Update the occupied bit board.
	this->emptySquares ^= fromToBoard; // Update the empty bit board.
}

void Position::unmakeMove(Move const & m)
{
	Move undo = m;
	undo.from = m.to;
	undo.to = m.from;
	makeMove(undo);
}

void Position::init()
{
}
