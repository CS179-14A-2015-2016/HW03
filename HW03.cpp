#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

//prints all elements in a vector
void vprint(vector<string> & v)
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		std::cout << *i;
	}
}

//determines what value would be in the step if ever 
int steprand(int& boardsize)
{
	int spaces = boardsize/2;
	random_device ran;
	mt19937 dev(ran());
	uniform_int_distribution<> dis(-spaces, spaces);

	return dis(dev);
}

//determines if a tile will have a random value or not
bool tilerand()
{
	random_device randev;
	mt19937 gen(randev());
	uniform_real_distribution<> dis(0,1);

	if (dis(gen) > 0.7)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	//variable initialize
	int boardsize;
	int pbuffer; //pausebuffer
	int winner = 0; //endcheck
	int tokenhold;
	int tplace = 1;
	int n;
	int onep;
	int twop;

	//boardsize input
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

	//inserts token to start
	midvec[tplace] = "@";

	//prints the board
	vprint(topvec);
	cout << endl;
	vprint(midvec);
	cout << endl;
	vprint(botvec);
	cout << endl;

	//calls the rand functions
	for (int i = 0; i < 20; i++)
	{
	
		if (tilerand() == true)
		{
			cout << "Tilerands: " << tilerand() << " " << endl;
			cout << "Steprands: " << steprand(boardsize) << " " << endl << endl;
		}
		else
		{
			cout << "Steprands: 0" << endl << endl;
		}
		
	}

	/*
	while (winner != 1)
	{
		cout << "Enter first move: ";
		cin >> onep;

		n = tplace + onep * 2;
		tplace = n;
		midvec[tplace] = "@";

		//prints the board
		vprint(topvec);
		cout << endl;
		vprint(midvec);
		cout << endl;
		vprint(botvec);
		cout << endl;
	}
	*/

	//pause buffer
	cin >> pbuffer;

	return EXIT_SUCCESS;
}
