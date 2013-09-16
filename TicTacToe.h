#ifndef TicTacToe_h
#define TicTacToe_h

#include <string>
#include <cstdint>

class TicTacToe
{
public:
    enum class Player : std::int8_t {
        none = 0,
        playerX = 1,
        playerO = 2
    };

	bool move(const int a, const int b) const {
		return isMoveInRange(a, b);
	}

	bool addMoveToBoard(const int a, const int b, Player player)  {
		return validateMoveOnBoard(a, b, player);
	}

	TicTacToe::Player threeInARow(Player player) {
		return whoHasThreeInARow(player);
	}

	bool canPlayerMakeNextMove(Player player) {
		return validPlayer(player);
	}


private:
	Player nextTurn = Player::playerX;
	Player board[3][3];

	bool isMoveInRange(const int a, const int b) const {
		return ((a > 0 && a < 4) && (b > 0 && b < 4)) ? true : false;
	}

	int getIndex(int a) {
		return --a;
	}

	bool isValidMove(const int a, const int b, const Player player) {
		Player boardValue = board[getIndex(a)][getIndex(b)];
		if (boardValue == Player::playerX || boardValue == Player::playerO) return false;
		board[getIndex(a)][getIndex(b)] = player;
		return true;
	}

	bool validateMoveOnBoard(const int a, const int b, const Player player)  {
		bool validMove = false;
		validMove = isMoveInRange(a ,b);
		if (!validMove) return false;
        if (!isValidMove(a, b, player)) return false;
		return true;
	}

	// I'm not shure this is a very good approach. I'll look up other solutions
	// when this is working as intended.
	TicTacToe::Player whoHasThreeInARow(Player player) {
		TicTacToe::Player p = Player::none;

		if (board[0][0] == board[0][1] && board[0][2] == player) return player;
		if (board[1][0] == board[1][1] && board[1][2] == player) return player;
//		( )( )( )
//		(x)(x)(x)
//		( )( )( )

		if (board[2][0] == board[2][1] && board[2][2] == player) return player;
		if (board[0][0] == board[1][1] && board[2][2] == player) return player;
//		(x)( )( )
//		( )(x)( )
//		( )( )(x)

		if (board[2][0] == board[1][1] && board[0][2] == player) return player;
		if (board[0][0] == board[1][0] && board[2][0] == player) return player;
		if (board[0][1] == board[1][1] && board[2][1] == player) return player;
//		( )(x)( )
//		( )(x)( )
//		( )(x)( )

		if (board[0][2] == board[1][2] && board[2][2] == player) return player;

		return p;
	}

	bool validPlayer(Player player) {
		if (player == nextTurn)
		{
			(player == Player::playerX) ? nextTurn = Player::playerO : nextTurn = Player::playerX;
			return true;
		}
		return false;
	}
};

#endif
