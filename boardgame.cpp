#include <iostream>
#include <string>

using namespace std;
int n, a, b, currentPos;
const string token = "@";

void init() {
    n = 0;
    a = 0;
    b = 0;
    currentPos = 0;
    cin.clear();
}

void printBoardTop() {
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            cout << "+" << "\n";
            break;
        }
        cout << "+-";
    }
}

void printBoardMid(string *arr) {
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            cout << "|" << "\n";
            break;
        }
        
        if (arr[i] != token) {
            cout << "|" << " ";
            
        }
        else {
            cout << "|" << arr[i];
        }
    }
}

void printBoardBot() {
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            cout << "+" << "\n";
            break;
        }
        cout << "+-";
    }
}

void playerMove(string *arr, int steps) {
    arr[currentPos] = " ";
    currentPos += steps;
    
    if (currentPos >= n) {
        int moveExcess = currentPos - (n - 1);
        currentPos = (n - 1) - moveExcess;
    }
    
    arr[currentPos] = token;
}

int main() {
    bool areGameAttributesAcceptable = false ;
    bool isPlayerWin = false;
    bool isPlayerAMove = true;
    
    init();
    
    while (areGameAttributesAcceptable == false) {
		cout << "Input size, min step value, and max step value: ";
		cin >> n >> a >> b;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "The values you entered are invalid.\n";
        }
        else if ((a < n) && (b < n) && (a <= b) && (n > 1) && (a > 0) && (b > 0)) {
            areGameAttributesAcceptable = true; //break;
        }
        else {
            cout << "The values you entered are invalid.\n";
        }
    }
    
    string *board = new string[n];    
    board[0] = token;
    
    while (isPlayerWin == false) {
        int move = 0;
        bool isMoveAcceptable = false;
        
        printBoardTop();
        printBoardMid(board);
        printBoardBot();
        
        if (currentPos == n - 1) {
            if (isPlayerAMove == true) {
                cout << "Player A Wins!";
            }
            else if (isPlayerAMove == false) {
                cout << "Player B Wins!";
            }
            break; //can't use isPlayerWin = true since the entire function would go through another cin in IsMoveAcceptable in line 123
        }
        
        if (isPlayerAMove == true) {
            cout << "A: ";
        }
        else if (isPlayerAMove == false) {
            cout << "B: ";
        }
        
        while (isMoveAcceptable == false) {
            cin >> move;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "The value you entered is invalid.\n";
            }
            else if ((move >= a) && (move <= b)) {
                isMoveAcceptable = true; //break;
            }
            else {
                cout << "The value you entered is invalid.\n";
            }
        }
        
        playerMove(board, move);
        
        if (currentPos == n - 1) {
            continue;
        }
        else if (isPlayerAMove == true) {
            isPlayerAMove = false;
        }
        else if (isPlayerAMove == false) {
            isPlayerAMove = true;
        }
    }
    
    cout << "\nPlay again? (Y/N)";
    string answer;
    cin >> answer;
    if ((answer == "Y") || (answer == "y")) {
        main();
    }
    return 0;
}