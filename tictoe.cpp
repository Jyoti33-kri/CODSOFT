#include <iostream>
using namespace std;

char board[3][3];
char current_marker;
int current_player;

// Function to reset the board for a new game
void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

// Function to draw the board
void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

// Function to place marker on board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "❌ Invalid move! Try again.\n";
        return false;
    }

    board[row][col] = current_marker;
    return true;
}

// Function to check for winner
char checkWinner() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' '; // no winner yet
}

// Function to switch players
void switchPlayer() {
    if (current_marker == 'X')
        current_marker = 'O';
    else
        current_marker = 'X';

    if (current_player == 1)
        current_player = 2;
    else
        current_player = 1;
}

// Function for one full match
void playMatch() {
    resetBoard();
    drawBoard();

    int move_count = 0;
    while (true) {
        int slot;
        cout << "Player " << current_player << " (" << current_marker << "), enter your move (1-9): ";
        cin >> slot;

        if (!placeMarker(slot)) continue;
        drawBoard();
        move_count++;

        char winner = checkWinner();
        if (winner == 'X' || winner == 'O') {
            cout << "🎉 Player " << current_player << " (" << winner << ") wins the game! 🎉\n";
            break;
        }

        if (move_count == 9) {
            cout << "😅 It's a draw!\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    cout << "🎮 Welcome to Tic-Tac-Toe Game 🎮\n";
    cout << "Player 1, choose your marker (X or O): ";
    cin >> current_marker;
    current_player = 1;

    char choice;
    do {
        playMatch();  // play one full game

        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            // Swap markers so the other player starts next time
            switchPlayer();
            cout << "\nStarting new match...\n";
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "\n👋 Thanks for playing Tic-Tac-Toe! Bye!\n";
    return 0;
}