#pragma once

#include <cstdint>
#include <intrin.h>

#ifdef BOARD_EXPORTS
#define BOARD_API _declspec(dllexport)
#else
#define BOARD_API _declspec(dllimport)
#endif

/* Begin Constant Hell. */

/* Size and Index constants. */
#define PIECE_TYPE_COUNT 12 
#define W_KING_INDEX 0
#define W_QUEEN_INDEX 1
#define W_ROOKS_INDEX 2
#define W_BISHOPS_INDEX 3
#define W_KNIGHTS_INDEX 4
#define W_PAWNS_INDEX 5
#define W_ENPASSANT_INDEX 6
#define B_KING_INDEX 7
#define B_QUEEN_INDEX 8
#define B_ROOKS_INDEX 9
#define B_BISHOPS_INDEX 10
#define B_KNIGHTS_INDEX 11
#define B_PAWNS_INDEX 12
#define B_ENPASSANT_INDEX 13

#define EMPTY 0x0ull
#define UNIVERSE 0xffffffffffffffffull

/* Begin square constants. */
#define a1 0x1ull
#define a2 0x100ull
#define a3 0x10000ull
#define a4 0x1000000ull
#define a5 0x100000000ull
#define a6 0x10000000000ull
#define a7 0x1000000000000ull
#define a8 0x100000000000000ull

#define b1 0x2ull
#define b2 0x200ull
#define b3 0x20000ull
#define b4 0x2000000ull
#define b5 0x200000000ull
#define b6 0x20000000000ull
#define b7 0x2000000000000ull
#define b8 0x200000000000000ull

#define c1 0x4ull
#define c2 0x400ull
#define c3 0x40000ull
#define c4 0x4000000ull
#define c5 0x400000000ull
#define c6 0x40000000000ull
#define c7 0x4000000000000ull
#define c8 0x400000000000000ull

#define d1 0x8ull
#define d2 0x800ull
#define d3 0x80000ull
#define d4 0x8000000ull
#define d5 0x800000000ull
#define d6 0x80000000000ull
#define d7 0x8000000000000ull
#define d8 0x800000000000000ull

#define e1 0x10ull
#define e2 0x1000ull
#define e3 0x100000ull
#define e4 0x10000000ull
#define e5 0x1000000000ull
#define e6 0x100000000000ull
#define e7 0x10000000000000ull
#define e8 0x1000000000000000ull

#define f1 0x20ull
#define f2 0x2000ull
#define f3 0x200000ull
#define f4 0x20000000ull
#define f5 0x2000000000ull
#define f6 0x200000000000ull
#define f7 0x20000000000000ull
#define f8 0x2000000000000000ull

#define g1 0x40ull
#define g2 0x4000ull
#define g3 0x400000ull
#define g4 0x40000000ull
#define g5 0x4000000000ull
#define g6 0x400000000000ull
#define g7 0x40000000000000ull
#define g8 0x4000000000000000ull

#define h1 0x80ull
#define h2 0x8000ull
#define h3 0x800000ull
#define h4 0x80000000ull
#define h5 0x8000000000ull
#define h6 0x800000000000ull
#define h7 0x80000000000000ull
#define h8 0x8000000000000000ull
/* End square constants. */

typedef uint64_t mask_t;
typedef uint64_t data_t;

/* Composed constants */
const data_t file_a = a1 | a2 | a3 | a4 | a5 | a6 | a7 | a8;
const data_t file_b = b1 | b2 | b3 | b4 | b5 | b6 | b7 | b8;
const data_t file_c = c1 | c2 | c3 | c4 | c5 | c6 | c7 | c8;
const data_t file_d = d1 | d2 | d3 | d4 | d5 | d6 | d7 | d8;
const data_t file_e = e1 | e2 | e3 | e4 | e5 | e6 | e7 | e8;
const data_t file_f = f1 | f2 | f3 | f4 | f5 | f6 | f7 | f8;
const data_t file_g = g1 | g2 | g3 | g4 | g5 | g6 | g7 | g8;
const data_t file_h = h1 | h2 | h3 | h4 | h5 | h6 | h7 | h8;

const data_t rank_1 = a1 | b1 | c1 | d1 | e1 | f1 | g1 | h1;
const data_t rank_2 = a2 | b2 | c2 | d2 | e2 | f2 | g2 | h2;
const data_t rank_3 = a3 | b3 | c3 | d3 | e3 | f3 | g3 | h3;
const data_t rank_4 = a4 | b4 | c4 | d4 | e4 | f4 | g4 | h4;
const data_t rank_5 = a5 | b5 | c5 | d5 | e5 | f5 | g5 | h5;
const data_t rank_6 = a6 | b6 | c6 | d6 | e6 | f6 | g6 | h6;
const data_t rank_7 = a7 | b7 | c7 | d7 | e7 | f7 | g7 | h7;
const data_t rank_8 = a8 | b8 | c8 | d8 | e8 | f8 | g8 | h8;

const data_t bdl_1 = h8;
const data_t bdl_2 = f8 | g7 | h6;
const data_t bdl_3 = d8 | e7 | f6 | g5 | h4;
const data_t bdl_4 = b8 | c7 | d6 | e5 | f4 | g3 | h2;
const data_t bdl_5 = a7 | b6 | c5 | d4 | e3 | f2 | g1;
const data_t bdl_6 = a5 | b4 | c3 | d2 | e1;
const data_t bdl_7 = a3 | b2 | c1;
const data_t bdl_8 = a1;

const data_t bdr_1 = a1;
const data_t bdr_2 = a5 | b6 | c7 | d8;
const data_t bdr_3 = a3 | b4 | c5 | d6 | e7 | f8;
const data_t bdr_4 = a1 | b2 | c3 | d4 | e5 | f6 | g7 | h8;
const data_t bdr_5 = c1 | d2 | e3 | f4 | g5 | h6;
const data_t bdr_6 = e1 | f2 | g3 | h4;
const data_t bdr_7 = g1 | h2;

const data_t wdr_1 = a8;
const data_t wdr_2 = a6 | b7 | c8;
const data_t wdr_3 = a4 | b5 | c6 | d7 | e8;
const data_t wdr_4 = a2 | b3 | c4 | d5 | e6 | f7 | g8;
const data_t wdr_5 = b1 | c2 | d3 | e4 | f5 | g6 | h7;
const data_t wdr_6 = d1 | e2 | f3 | g4 | h5;
const data_t wdr_7 = f1 | g2 | h3;
const data_t wdr_8 = h1;


const data_t wdl_1 = g8 | h7;
const data_t wdl_2 = e8 | f7 | g6 | h5;
const data_t wdl_3 = c8 | d7 | e6 | f5 | g4 | h3;
const data_t wdl_4 = a8 | b7 | c6 | d5 | e4 | f3 | g2 | h1;
const data_t wdl_5 = a6 | b5 | c4 | d3 | e2 | f1;
const data_t wdl_6 = a4 | b3 | c2 | d1;
const data_t wdl_7 = a2 | b1;


class BOARD_API Board
{
	public:
		/* Constructors */
		Board();
		Board(int index); // Construct with bit at `index` set.
		Board(int col, int row); // Construct with bit at `(col, row)` set.
		Board(data_t data); // Construct from a mask_t bitmask.
		Board(Board const& other); // Construct from another Board.

		/* Assignment Operators */
		Board& operator=(data_t data);
		Board& operator=(Board const& other);

		/* Set bits */
		void set();
		void set(int index);
		void set(int col, int row);
		void set(data_t const& data);
		void set(Board const& board);

		/* Unset bits */
		void reset();
		void reset(int index);
		void reset(int col, int row);
		void reset(data_t const& data);
		void reset(Board const& board);

		/* Toggle bits */
		void toggle(int index);
		void toggle(int col, int row);
		void toggle(data_t const& data);
		void toggle(Board const& board);

		/* Accessors */
		Board operator~() const; // Inverse of the board.
		operator void*() const; // Truthiness
		mask_t operator()() const; // Gets the bitmask.

		/* Bit-wise OR */
		Board& operator|=(Board const& board);
		Board& operator|=(data_t const& data);
		Board operator|(Board const& board2);
		Board operator|(data_t board2);

		/* Bit-wise AND */
		Board& operator&=(Board const& board);
		Board& operator&=(data_t const& data);
		Board operator&(Board const& board2); // Not sure about these two lol.
		Board operator&(data_t board2);

		/* Bit-wise XOR */
		Board& operator^=(Board const& board);
		Board& operator^=(data_t const& data);
		Board operator^(Board const& board2);
		Board operator^(data_t board2);
		
		/* Comparisons */
		bool operator==(Board const& board2);
		bool operator==(data_t board2);
		bool operator!=(Board const& board2);
		bool operator!=(data_t board2);

	private:
		data_t board;
};