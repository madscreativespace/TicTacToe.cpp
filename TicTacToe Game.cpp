// Purpose: Create a 2 player Tic-Tac-Toe game using a class that allows user input as Player X & O.
//  main.cpp
//  TicTacToe Game
//  Created by Madeleine Daniels on 1/3/24.

#include <iostream>
#include <string>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    bool gameWon;
    bool tie;

public:
    TicTacToe() {
        // Initialize the board with asterisks
        for (int rowCount = 0; rowCount < 3; ++rowCount) {
            for (int colCount = 0; colCount < 3; ++colCount) {
                board[rowCount][colCount] = '*';
            }
        }
        gameWon = false;
        tie = false;
    }

    void displayBoard() {
        cout << "  1 2 3" << endl;
        for (int rowCount = 0; rowCount < 3; ++rowCount) {
            cout << rowCount + 1 << " ";
            for (int colCount = 0; colCount < 3; ++colCount) {
                cout << board[rowCount][colCount] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    // Validate move
    bool isMoveValid(int row, int col) {
        // Check if the move is within bounds and the selected location is empty
        return (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == '*');
    }
    // Player 1 as XPlay
    void XPlay(int row, int col) {
        if (isMoveValid(row, col)) {
            board[row - 1][col - 1] = 'X';
        } else {
            cout << "Invalid move. Try again.\n";
            XTurn();
        }
    }
    // Player 2 as OPlay
    void OPlay(int row, int col) {
        if (isMoveValid(row, col)) {
            board[row - 1][col - 1] = 'O';
        } else {
            cout << "Invalid move. Try again.\n";
            OTurn();
        }
    }

    bool checkWinner(char player) {
        // Check rows and columns
        for (int rowCount = 0; rowCount < 3; ++rowCount) {
            if ((board[rowCount][0] == player && board[rowCount][1] == player && board[rowCount][2] == player) ||
                (board[0][rowCount] == player && board[1][rowCount] == player && board[2][rowCount] == player)) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            return true;
        }

        return false;
    }

    void determineAWinner() {
        if (checkWinner('X')) {
            cout << "Player 1 (X) wins!\n";
            gameWon = true;
        } else if (checkWinner('O')) {
            cout << "Player 2 (O) wins!\n";
            gameWon = true;
        } else if (isBoardFull()) {
            cout << "It's a tie!\n";
            tie = true;
        }
    }
    // Check if the board is full
    bool isBoardFull() {
        for (int rowCount = 0; rowCount < 3; ++rowCount) {
            for (int colCount = 0; colCount < 3; ++colCount) {
                if (board[rowCount][colCount] == '*') {
                    return false;
                }
            }
        }
        return true;
    }
    // Check if game is over
    bool isGameOver() {
        return gameWon || tie;
    }
    // Prompt players to make their moves
    void XTurn() {
        int row, col;
        cout << "Player 1 (X), enter row and column (e.g., 1 2): ";
        cin >> row >> col;
        XPlay(row, col);
    }

    void OTurn() {
        int row, col;
        cout << "Player 2 (O), enter row and column (e.g., 1 2): ";
        cin >> row >> col;
        OPlay(row, col);
    }
    static const string instructions;
};

// Definition of the constant string
const string TicTacToe::instructions = "Instructions: Enter the row and column numbers (1, 2, or 3) separated by a space.";

int main() {
    TicTacToe game;

    cout << "Lets play Tic-Tac-Toe!\n";
    cout << "Instructions: Enter the row and column numbers (1, 2, or 3) separated by a space.\n";
    cout << endl;
    
    while (!game.isGameOver()) {
        game.displayBoard();
        game.XTurn();
        game.determineAWinner();

        if (!game.isGameOver()) {
            game.displayBoard();
            game.OTurn();
            game.determineAWinner();
        }
    }

    return 0;
}
