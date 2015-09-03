#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int n;
int a;
int b;
int c;
int i;
int z[5];
bool invalid;
int tokenPosition;
int numMoves;
char player;
string again;

void turn(int x, int y) {
	int j = 1;
	do {
		cout << "+--";
		j += 1;
	} while (j <= n);
	cout << "+\n";
		
	while ((x < n) && (y != 0)) {
		x += 1;
		y -= 1;
	}

	while (y != 0) {
		x -= 1;
		y -= 1;
	}

	j = 1;
	c = n / 3;
	i = 0;
	do {
		if (c == x) { x += z[i]; }
		i++;
		c += 3;
	} while (i < 5);

	j = 1;
	c = n / 3;
	i = 0;
	do {
		if (j == x) { cout << "|@ "; }
		else if (j == c && c != n && i < 5 ) {
			if (z[i] == 0) { cout << "|  "; }
			else if (z[i] > 0) { cout << "| " << z[i]; }
			else { cout << "|" << z[i]; }
			c += 3;
			i++;
		}
		else { cout << "|  "; }
		j += 1;
	} while (j <= n);
	cout << "|\n";

	j = 1;
	do {
		cout << "+--";
		j += 1;
	} while (j <= n);
	cout << "+\n";
	tokenPosition = x;
	i = 0;
	c = n / 3;
}

void check(int x) {
	if (x == n) {
		cout << "Player " << player << " wins!";
	}

	else {
		if (player == 'A') { player = 'B'; }
		else if (player == 'B') { player = 'A'; }

		do {
			invalid = false;
			cout << player << "> ";
			cin >> numMoves;
			if ((numMoves < a) || (numMoves > b)) {
				cout << "Invalid input. Please try again.\n";
				invalid = true;
			}
		} while (invalid);
	}

}


int main() {

	do {
		invalid = false;
		n = 0;
		a = 0;
		b = 0;
		cout << "n = ";
		cin >> n;
		if (n <= 1) { invalid = true; }
		cout << "a = ";
		cin >> a;
		if (a > n - 1) { invalid = true; }
		cout << "b = ";
		cin >> b;
		if ((b < a) || (b > n - 1)) { invalid = true; }

		if (invalid) { cout << "Invalid inputs. Please try again.\n"; }
	} while (invalid);

	tokenPosition = 1;
	numMoves = 0;
	player = 'B';
	c = n / 3;
	if (n < 6) {
		for (int i = 0; i < 5; i++) {
			z[i] = 0;
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			z[i] = rand() % 4 - 2;
		}
	}
	i = 0;

	while (tokenPosition != n) {
		turn(tokenPosition, numMoves);
		check(tokenPosition);
	}

	cout << "\nPlay again? (y or n): ";
	cin >> again;
	if (again == "y") {
		main();
	}

	return 0;
}