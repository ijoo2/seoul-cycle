#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NemoTest
{		
	TEST_CLASS(NemoUnitTests)
	{
	public:
		
		TEST_METHOD(BoardTest)
		{
			data_t test_mask, expected;
			test_mask = 0x1010101ull;
			Board board, other, optest;
			board = Board();
			other = Board();

			Assert::AreEqual(board(), EMPTY);
			Assert::AreEqual(board == EMPTY, true); // Test eq operator with data_t
			Assert::AreEqual(board != UNIVERSE, true); // test neg operator with data_t

			board.set();
			Assert::AreEqual(board(), UNIVERSE);
			board.reset();
			Assert::AreEqual(board(), EMPTY);

			board.set(0); // set a1
			Assert::AreEqual(board(), a1);
			
			board.set(0); // Should do nothing
			Assert::AreEqual(board(), a1);

			board.reset(0); // clear board
			Assert::AreEqual(board(), EMPTY);
			
			board.set(1); // set b1
			Assert::AreEqual(board(), b1);
			board.reset();

			board.set(test_mask);
			Assert::AreEqual(board(), test_mask);
			board.toggle(test_mask); // should be EMPTY
			Assert::AreEqual(board(), EMPTY);
			board.toggle(test_mask);
			Assert::AreEqual(board(), test_mask);
			board.reset();

			other.set(1);
			board.set(other); // both b1s are set
			Assert::AreEqual(board(), other());
			board.reset();
			other.reset();

			board.set(bdl_3);
			other.set(wdr_3);
			optest = board | other;
			Assert::AreEqual(optest() == (bdl_3 | wdr_3), true);
			optest.reset();

			optest = board & other; // disjoint, so should be EMPTY
			expected = (bdl_3 & wdr_3);

			Assert::AreEqual(optest(), expected);
			Assert::AreEqual(optest(), EMPTY);
			optest = board & d8;
			Assert::AreEqual(optest(), d8);
			optest.reset();

			optest = board ^ other;
			expected = bdl_3 ^ wdr_3;
			Assert::AreEqual(optest(), expected);
			board.reset();
			other.reset();
			optest.reset();

			board.set(a1);
			optest |= board;
			Assert::AreEqual(optest(), a1);
			optest &= (a1 | b1);
			Assert::AreEqual(optest(), a1);
			optest &= a1;
			Assert::AreEqual(optest(), a1);
			optest ^= a1;
			Assert::AreEqual(optest(), EMPTY);
			board.reset();
			optest.reset();

			optest = ~board;
			Assert::AreEqual(optest(), UNIVERSE); // inverse of EMPTY == UNIVERSE
			Assert::AreEqual(board(), EMPTY); // board should be untouched
			Assert::AreEqual(board != optest, true); // test neg operator between boards
			optest = ~optest;
			Assert::AreEqual(optest(), EMPTY);
			Assert::AreEqual(board == optest, false); // test eq operator between boards
		}

	};
}