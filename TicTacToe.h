#ifndef TicTacToe_h
#define TicTacToe_h

#include <string>
#include <cstdint>

class TicTacToe
{
public:
    enum class BoardValues : std::int8_t {
        isEmpty = 0,
        playerX = 1,
        playerO = 2
    };

	BoardValues board[3][3];

	bool move(const int a, const int b) const {
		return isMoveInRange(a, b);
	}

	bool addMoveToBoard(const int a, const int b, BoardValues player)  {
		return validateMoveOnBoard(a, b, player);
	}

private:
	bool isMoveInRange(const int a, const int b) const {
		return ((a > 0 && a < 4) && (b > 0 && b < 4)) ? true : false;
	}

	int getIndex(int a) {
		return --a;
	}

	bool isValidMove(const int a, const int b, const BoardValues player) {
		BoardValues boardValue = board[getIndex(a)][getIndex(b)];
		if (boardValue == BoardValues::playerX || boardValue == BoardValues::playerO) return false;
		board[getIndex(a)][getIndex(b)] = player;
		return true;
	}

	bool validateMoveOnBoard(const int a, const int b, const BoardValues player)  {
		bool validMove = false;
		validMove = isMoveInRange(a ,b);
		if (!validMove) return false;
        if (!isValidMove(a, b, player)) return false;
		return true;
	}
};

#endif
