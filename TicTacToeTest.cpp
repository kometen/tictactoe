#include "gmock/gmock.h"
#include "TicTacToe.h"

using namespace testing;

class TicTacToeMoves: public Test {
public:
	TicTacToe tictactoe;
};

TEST_F(TicTacToeMoves, MakeShureMovesAreWithInBounds) {
	ASSERT_THAT(tictactoe.move(1, 2), Eq(true));
	ASSERT_THAT(tictactoe.move(0, 2), Eq(false));
	ASSERT_THAT(tictactoe.move(-1, 4), Eq(false));
	ASSERT_THAT(tictactoe.move(2, 4), Eq(false));
}

TEST_F(TicTacToeMoves, MakeShureThatNextMoveIsPossible) {
	ASSERT_THAT(tictactoe.addMoveToBoard(1, 2, TicTacToe::BoardValues::playerX), Eq(true));
	ASSERT_THAT(tictactoe.addMoveToBoard(1, 2, TicTacToe::BoardValues::playerO), Eq(false));
	ASSERT_THAT(tictactoe.addMoveToBoard(1, 3, TicTacToe::BoardValues::playerO), Eq(true));
}
