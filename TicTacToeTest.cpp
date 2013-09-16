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
	ASSERT_THAT(tictactoe.addMoveToBoard(1, 1, TicTacToe::Player::playerX), Eq(true));
	ASSERT_THAT(tictactoe.addMoveToBoard(1, 1, TicTacToe::Player::playerO), Eq(false));
	ASSERT_THAT(tictactoe.addMoveToBoard(1, 3, TicTacToe::Player::playerO), Eq(true));
}

TEST_F(TicTacToeMoves, DetectWhenAPlayerHasThreeInARow) {
	ASSERT_THAT(tictactoe.threeInARow(TicTacToe::Player::none), Eq(TicTacToe::Player::none));
	ASSERT_THAT(tictactoe.threeInARow(TicTacToe::Player::playerX), Eq(TicTacToe::Player::none));
	ASSERT_THAT(tictactoe.addMoveToBoard(1, 1, TicTacToe::Player::playerX), Eq(true));
	ASSERT_THAT(tictactoe.threeInARow(TicTacToe::Player::playerX), Eq(TicTacToe::Player::none));
	ASSERT_THAT(tictactoe.addMoveToBoard(1, 2, TicTacToe::Player::playerX), Eq(true));
	ASSERT_THAT(tictactoe.threeInARow(TicTacToe::Player::playerX), Eq(TicTacToe::Player::none));
	ASSERT_THAT(tictactoe.addMoveToBoard(1, 3, TicTacToe::Player::playerX), Eq(true));
	ASSERT_THAT(tictactoe.threeInARow(TicTacToe::Player::playerX), Eq(TicTacToe::Player::playerX));
}

TEST_F(TicTacToeMoves, MakeShureThatEachPlayerTakeTurns) {
	ASSERT_THAT(tictactoe.canPlayerMakeNextMove(TicTacToe::Player::playerX), Eq(true));
	ASSERT_THAT(tictactoe.canPlayerMakeNextMove(TicTacToe::Player::playerX), Eq(false));
	ASSERT_THAT(tictactoe.canPlayerMakeNextMove(TicTacToe::Player::playerO), Eq(true));
	ASSERT_THAT(tictactoe.canPlayerMakeNextMove(TicTacToe::Player::playerO), Eq(false));
}