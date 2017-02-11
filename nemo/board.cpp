#include "board.h"

using namespace std;

Board::Board()
{
	this->board = EMPTY;
}

Board::Board(Board const & other)
{
	this->board = other.board;
}

Board::Board(int index)
{
	this->board = a1 << index;
}

Board::Board(int col, int row)
{
	this->board = a1 << (row * 8 + col);
}

Board::Board(data_t data)
{
	this->board = data;
}

Board & Board::operator=(Board const & other)
{
	if (this != &other)
	{
		this->board = other.board;
	}
	return *this;
}

Board & Board::operator=(data_t data)
{
	this->board = data;
	return *this;
}

void Board::set(int col, int row)
{
	this->board |= a1 << (row * 8 + col);
}

void Board::set()
{
	this->board |= UNIVERSE;
}

void Board::set(int index)
{
	this->board |= a1 << index;
}

void Board::set(data_t const& data)
{
	this->board |= data;
}

void Board::set(Board const & board)
{
	this->board |= board.board;
}

void Board::reset(int col, int row)
{
	this->board &= ~(a1 << (row * 8 + col));
}

void Board::reset()
{
	this->board = EMPTY;
}

void Board::reset(int index)
{
	this->board &= ~(a1 << index);
}

void Board::reset(data_t const & data)
{
	this->board &= ~data;
}

void Board::reset(Board const & board)
{
	this->board &= ~board.board;
}

void Board::toggle(int col, int row)
{
	this->board ^= a1 << (row * 8 + col);
}

void Board::toggle(int index)
{
	this->board ^= a1 << index;
}

void Board::toggle(data_t const & data)
{
	this->board ^= data;
}

void Board::toggle(Board const & board)
{
	this->board ^= board.board;
}

Board Board::operator~() const
{
	data_t data = ~(this->board);
	return Board(data);
}

Board::operator void*() const
{
	return 0x0;
}

data_t Board::operator()() const
{
	return this->board;
}

Board & Board::operator|=(Board const & board)
{
	this->set(board);
	return *this;
}

Board & Board::operator|=(data_t const & data)
{
	this->board |= data;
	return *this;
}

Board Board::operator|(Board const & board2)
{
	
	return Board(this->board | board2.board);
}

Board Board::operator|(data_t board2)
{
	return Board(this->board | board2);
}

Board & Board::operator&=(Board const & board)
{
	this->board &= board.board;
	return *this;
}

Board & Board::operator&=(data_t const & data)
{
	this->board &= data;
	return *this;
}

Board Board::operator&(Board const & board2)
{
	return Board(this->board & board2.board);
}

Board Board::operator&(data_t board2)
{
	return Board(this->board & board2);
}

Board & Board::operator^=(Board const & board)
{
	this->board ^= board.board;
	return *this;
}

Board & Board::operator^=(data_t const& data)
{
	this->board ^= data;
	return *this;
}

Board Board::operator^(Board const & board2)
{
	return Board(this->board ^ board2.board);
}

Board Board::operator^(data_t board2)
{
	return Board(this->board ^ board2);
}

bool Board::operator==(Board const & board2)
{
	return (this->board == board2.board);
}

bool Board::operator==(data_t board2)
{
	return (this->board == board2);
}

bool Board::operator!=(Board const & board2)
{
	return (this->board != board2.board);
}

bool Board::operator!=(data_t board2)
{
	return (this->board != board2);
}
