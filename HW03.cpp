#include <iostream>
#include <string>
#include <vector>

using namespace std;

//prints all elements in a vector
void vprint(vector<string> & v)
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		std::cout << *i;
	}
}

int main()
{
	//variable initialize
	int boardsize;
	int pbuffer;
	cout << "Please enter the number of cells...";
	cin >> boardsize;

	//total board
	vector<string> topvec = { "+", "-", "+" };
	vector<string> midvec = { "|", " " ,"|" };
	vector<string> botvec = { "+", "-", "+" };

	//strings to add to the board
	vector<string> totop = { "-", "+" };
	vector<string> tomid = { " ", "|" };
	vector<string> tobot = { "-", "+" };

	//boardsize increase
	topvec.reserve(topvec.size() + (totop.size()*boardsize));
	midvec.reserve(midvec.size() + (tomid.size()*boardsize));
	botvec.reserve(botvec.size() + (tobot.size()*boardsize));

	//increase boardsize by adding to the to- vectors
	for (int count = 1; count < boardsize; count++)
	{
		topvec.insert(topvec.end(), totop.begin(), totop.end());
		midvec.insert(midvec.end(), tomid.begin(), tomid.end());
		botvec.insert(botvec.end(), tobot.begin(), tobot.end());
	}

	//prints the board
	vprint(topvec);
	cout << endl;
	vprint(midvec);
	cout << endl;
	vprint(botvec);
	cout << endl;


	//pause buffer
	cin >> pbuffer;

	return EXIT_SUCCESS;
}