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
	int moves;
	bool player = true;
	cout << "Please enter the number of cells...";
	cin >> boardsize;
	if(player == true){
		cout << "Please enter number of tiles to move, Player 1.";
		cin >> moves;
		player = false;
	}else{
		cout << "Please enter number of tiles to move, Player 2.";
		cin >> moves;
		player = true;
	}

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
	//replaces blank with token depending on move(in progress)
	midvec[2*moves] = "@";
	
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
