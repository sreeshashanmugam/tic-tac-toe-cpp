#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Initialize Board
void initializeBoard() {
    char position = '1';

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = position++;
        }
    }
}

// Display Board
void displayBoard() {
    cout << "\n";

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {
            cout << " " << board[i][j];

            if(j < 2)
                cout << " |";
        }

        cout << "\n";

        if(i < 2)
            cout << "-----------\n";
    }

    cout << "\n";
}

// Make Move
bool makeMove(int choice) {

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

// Check Winner
bool checkWinner() {

    // Rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2]) {
            return true;
        }
    }

    // Columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i]) {
            return true;
        }
    }

    // Diagonals
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2]) {
        return true;
    }

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

// Check Draw
bool checkDraw() {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            if(board[i][j] != 'X' &&
               board[i][j] != 'O') {
                return false;
            }
        }
    }

    return true;
}

// Switch Player
void switchPlayer() {

    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main() {

    char replay;

    do {

        initializeBoard();
        currentPlayer = 'X';

        bool gameOver = false;

        while(!gameOver) {

            displayBoard();

            int choice;

            cout << "Player "
                 << currentPlayer
                 << ", enter position (1-9): ";

            cin >> choice;

            // Input Validation
            if(choice < 1 || choice > 9) {
                cout << "Invalid position!\n";
                continue;
            }

            // Check if move possible
            if(!makeMove(choice)) {
                cout << "Position already taken!\n";
                continue;
            }

            // Winner Check
            if(checkWinner()) {

                displayBoard();

                cout << "Player "
                     << currentPlayer
                     << " Wins!\n";

                gameOver = true;
            }

            // Draw Check
            else if(checkDraw()) {

                displayBoard();

                cout << "Game Draw!\n";

                gameOver = true;
            }

            // Switch Turn
            else {
                switchPlayer();
            }
        }

        cout << "Play Again? (y/n): ";
        cin >> replay;

    } while(replay == 'y' || replay == 'Y');

    cout << "Thank You for Playing!\n";

    return 0;
}
