#include "board.h"
#include "assert.h"
#include "stdio.h"
#include <iostream>

#define DEBUG_RUN_TESTS 1

using namespace std;

void test_board()
{
	data_t test_mask, expected;
	test_mask = 0x1010101ull;
	Board board, other, optest;
	board = Board();
	other = Board();

	assert(board() == EMPTY);
	assert(board == EMPTY); // test eq operator with data_t
	assert(board != UNIVERSE); //test neq operator with data_t

	board.set(); // set all squares.
	assert(board() == UNIVERSE);
	board.reset();
	assert(board() == EMPTY);

	board.set(0); // set a1
	assert(board() == a1);

	board.set(0); // Should do nothing.
	assert(board() == a1);

	board.reset(0); // clear board.
	assert(board() == EMPTY);

	board.set(1); // set b1
	assert(board() == b1);
	board.reset();

	board.set(1, 0); // set b1
	assert(board() == b1);
	board.reset();

	board.set(test_mask);
	assert(board() == test_mask);
	board.toggle(test_mask); // should be EMPTY
	assert(board() == EMPTY);
	board.toggle(test_mask);
	assert(board() == test_mask);
	board.reset();

	board.reset();
	other.set(1);
	board.set(other); // both b1s are set
	assert(board() == other());
	board.reset();
	other.reset();

	board.set(bdl_3);
	other.set(wdr_3);
	optest = board | other;
	assert(optest() == (bdl_3 | wdr_3));
	optest.reset();

	optest = board & other; // disjoint, so should be EMPTY.
	expected = (bdl_3 & wdr_3);
	
	assert(optest() == expected);
	assert(optest() == EMPTY);
	optest = board & d8;
	assert(optest() == d8);
	optest.reset();

	optest = board ^ other;
	expected = bdl_3 ^ wdr_3;
	assert(optest() == expected);
	board.reset();
	other.reset();
	optest.reset();

	board.set(a1);
	optest |= board;
	assert(optest() == a1);
	optest &= (a1 | b1);
	assert(optest() == a1);
	optest &= a1;
	assert(optest() == a1);
	optest ^= a1;
	assert(optest() == EMPTY);
	board.reset();
	optest.reset();

	optest = ~board;
	assert(optest() == UNIVERSE); // inverse of EMPTY == UNIVERSE.
	assert(board() == EMPTY); // board should be untouched!
	assert(board != optest); // test neq operator between boards.
	optest = ~optest;
	assert(optest() == EMPTY);
	assert(board == optest); // test eq operator between boards.
}

void run_tests() 
{
	test_board();
}

int main()
{
	if (DEBUG_RUN_TESTS) { run_tests(); }
	return 0;
}