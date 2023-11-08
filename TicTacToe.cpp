#include <iostream>
#include <limits>
using namespace std;

// Defining Global Vars
char tttb[3][3] = {
{' ', ' ', ' '},
{' ', ' ', ' '},
{' ', ' ', ' '}};

const char player1 = 'X';
const char player2 = 'O';

void PrintMatrix() {
    for (int i = 0; i < 3; i++) {
        cout << tttb[i][0] << "|"
        << tttb[i][1] << "|"
        << tttb[i][2] << endl;
        if (i != 2) cout << "-----" << endl;
    }
}

bool isValidLocation(int x, int y) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Please enter a int value between 0 and 2." << endl;
        return false;
    }
    if (x >= 3 || x < 0 || y < 0 || y >= 3) {
            cout << "Invalid Input. Please enter a int value between 0 and 2." << endl;
            return false;
        }

    if (tttb[x][y] != ' ') {
        cout << "Location already taken." << endl;
        return false;
    }

    return true;
}

void Capture_xy_Location(char player) {
    int x,y;
    do {
        cout << "Where do you want to place an " << player << "?" << endl;
        cout << "Row: ";
        cin >> x;
        cout << "Col: ";
        cin >> y;

        if(isValidLocation(x, y)) {
            tttb[x][y] = player;
            return;
        }

    } while (true); // FIXME loop condition
}

bool isWinner(char player) {
    bool isWinner = false;
    // Check rows
    isWinner = isWinner || (tttb[0][0] == player &&
    tttb[0][1] == player &&
    tttb[0][2] == player);
    isWinner = isWinner || (tttb[1][0] == player &&
    tttb[1][1] == player &&
    tttb[1][2] == player);
    isWinner = isWinner || (tttb[2][0] == player &&
    tttb[2][1] == player &&
    tttb[2][2] == player);
    // Check columns
    isWinner = isWinner || (tttb[0][0] == player &&
    tttb[1][0] == player &&
    tttb[2][0] == player);
    isWinner = isWinner || (tttb[0][1] == player &&
    tttb[1][1] == player &&
    tttb[2][1] == player);
    isWinner = isWinner || (tttb[0][2] == player &&
    tttb[1][2] == player &&
    tttb[2][2] == player);
    // Check diagonals
    isWinner = isWinner || (tttb[0][0] == player &&
    tttb[1][1] == player &&
    tttb[2][2] == player);
    isWinner = isWinner || (tttb[0][2] == player &&
    tttb[1][1] == player &&
    tttb[2][0] == player);

    // if (isWinner) cout << player << "'s wins!" << endl;
    return isWinner;
}

bool isTie() {
    bool boardFull = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tttb[i][j] == ' ') {
                boardFull = false;
                break;
            }
        }
        if (!boardFull) break;
    }
    if (boardFull) return true;

    return false;
}

void PlayTurn(char player) {
    PrintMatrix();
    Capture_xy_Location(player);
    if (isWinner(player)) {
        PrintMatrix();
        cout << player << "'s wins!" << endl; 
        return;
    }
    if(isTie()) {
        PrintMatrix();
        cout << "Tie!" << endl; 
        return;
    }
    return;
}

int main() {
    int turnCount = 5;         // Backup counter instead of infinte loop
    while(turnCount > 0) {
        PlayTurn(player1);
        if(isTie() || isWinner(player1)) return 0;

        PlayTurn(player2);
        if(isWinner(player2)) return 0;
    }
    turnCount--;
    return 0;
}
