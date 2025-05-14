#include <bits/stdc++.h>
using namespace std;

class TicTacToe {
private:
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    char currentplayer = 'X';
    char currentnumber = '1';
    int times = 0;

    void printBoard() {
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
        cout << "---+---+---\n";
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
        cout << "---+---+---\n";
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
    }

    bool checkLine(int a, int b, int c) {
        return board[a] == board[b] && board[b] == board[c];
    }

    bool checkWin() {
        // check horizontal
        if (checkLine(0, 1, 2) || checkLine(3, 4, 5) || checkLine(6, 7, 8))
            return true;
        // check vertical
        if (checkLine(0, 3, 6) || checkLine(1, 4, 7) || checkLine(2, 5, 8))
            return true;
        // check diagonals0
        if (checkLine(0, 4, 8) || checkLine(2, 4, 6))
            return true;
        return false;
    }

public:
    void play() {
        cout << "-- Tic Tac Toe -- CSIE@CGU\n";
        cout << "Player 1 (X) - Player 2 (O)\n";
        printBoard();
        while (times < 9) {
            cout << "==> Player " << currentnumber << " (" << currentplayer << "), enter a number:";
            int position;
            cin >> position;

            if (position < 1 || position > 9 || board[position - 1] == 'X' || board[position - 1] == 'O') {
                cout << "==> Invalid value, please enter again\n";
                continue;
            }

            board[position - 1] = currentplayer;
            times++;
            printBoard();

            if (checkWin()) {
                cout << "==> Player " << currentnumber << " wins!\n";
                return;
            }

            currentplayer = (currentplayer == 'X') ? 'O' : 'X';
            currentnumber = (currentnumber == '1') ? '2' : '1';
        }
        cout << "==> Game draw\n";
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
