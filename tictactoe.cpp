// tictactoe.cpp

#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int r, int c, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);


int main() {
    runGame();

    return 0;
}

void runGame() {
    string gameBoard[ROWS][COLS];
    bool currentPlayer = true;
    string winner = "";

    do {
        getUserInput(currentPlayer, gameBoard);
        printCurrentBoard(gameBoard);
        winner = getWinner(gameBoard);
        currentPlayer = !currentPlayer;
    } while (winner == "");

    if (winner == "c") {
        cout << "The game is a tie." << endl;
    }
    else {
        cout << "Player " << winner << " has won " << endl;
    }
}

void initializeGameBoard(string gameBoard[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            gameBoard[r][c] = "";
        }
    }
}

void printCurrentBoard(string gameBoard[ROWS][COLS]) {
    cout << gameBoard[0][0] << "|" << gameBoard[0][1] << "|" << gameBoard[0][2] << endl;
    cout << "-----" << endl;
    cout << gameBoard[1][0] << "|" << gameboard[1][1] << "|" << gameBoard[1][2] << endl;
    cout << "-----" << endl;
    cout << gameBoard[2][0] << "|" << gameBoard[2][1] << "|" << gameBoard[2][2] << endl;
}

void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]) {
    int r, c;
    bool occuipied = false;

    if (xTurn) {
        cout << "X's Turn" << endl;
    }
    else {
        cout << "O's Turn" << endl
    }

    do {
        do {
            cout << "Row (0-2): ";
            cin >> r; 
        } while (r < 0 || r > 2);

        do {
            cout << "Col (0-2): ";
            cin >> c;
        } while (col < 0 || col > 2);

        if (occupied) {
            cout << "Cell already occupied." << endl;
        }
    } while (occupied);

    if (xTurn) {
        gameBoard[r][c] = "x";
    }
    else {
        gameBoard[r][c] = "o";
    }
}

bool cellAlreadyOccupied(int r, int c, string gameBoard[ROWS][COLS]) {
    return gameBoard[r][c] != "";
}

string getWinner(string gameBoard[ROWS][COLS]) {
    string winner = "";

    if (gameBoard[0][0] == "x" && gameBoard[0][1] == "x" && gameBoard[0][2] == "x") { winner = "x"; }
	if (gameBoard[1][0] == "x" && gameBoard[1][1] == "x" && gameBoard[1][2] == "x") { winner = "x"; }
	if (gameBoard[2][0] == "x" && gameBoard[2][1] == "x" && gameBoard[2][2] == "x") { winner = "x"; }
	if (gameBoard[0][0] == "x" && gameBoard[1][0] == "x" && gameBoard[2][0] == "x") { winner = "x"; }
	if (gameBoard[0][1] == "x" && gameBoard[1][1] == "x" && gameBoard[2][1] == "x") { winner = "x"; }
	if (gameBoard[0][2] == "x" && gameBoard[1][2] == "x" && gameBoard[2][2] == "x") { winner = "x"; }
	if (gameBoard[0][0] == "x" && gameBoard[1][1] == "x" && gameBoard[2][2] == "x") { winner = "x"; }
	if (gameBoard[2][0] == "x" && gameBoard[1][1] == "x" && gameBoard[0][2] == "x") { winner = "x"; }

	if (gameBoard[0][0] == "o" && gameBoard[0][1] == "o" && gameBoard[0][2] == "o") { winner = "o"; }
	if (gameBoard[1][0] == "o" && gameBoard[1][1] == "o" && gameBoard[1][2] == "o") { winner = "o"; }
	if (gameBoard[2][0] == "o" && gameBoard[2][1] == "o" && gameBoard[2][2] == "o") { winner = "o"; }
	if (gameBoard[0][0] == "o" && gameBoard[1][0] == "o" && gameBoard[2][0] == "o") { winner = "o"; }
	if (gameBoard[0][1] == "o" && gameBoard[1][1] == "o" && gameBoard[2][1] == "o") { winner = "o"; }
	if (gameBoard[0][2] == "o" && gameBoard[1][2] == "o" && gameBoard[2][2] == "o") { winner = "o"; }
	if (gameBoard[0][0] == "o" && gameBoard[1][1] == "o" && gameBoard[2][2] == "o") { winner = "o"; }
	if (gameBoard[2][0] == "o" && gameBoard[1][1] == "o" && gameBoard[0][2] == "o") { winner = "o"; }

	if (isBoardFull(gameBoard)) { winner = "c"; }

	return winner;
}

bool isBoardFull(string gameBoard[ROWS][COLS]) {
    bool boardFull = true;
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            if (gameBoard[r][c] == "") {
                boardFull = false;
            }
        }
    }
    return boardFull;
}