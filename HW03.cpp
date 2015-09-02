#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <limits>

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
	int spaces = boardsize / 2;
	random_device ran;
	mt19937 dev(ran());
	uniform_int_distribution<> dis(-spaces, spaces);
	int a = dis(dev);
	return a;
}

//determines if a tile will have a random value or not
bool tilerand()
{
	random_device randev;
	mt19937 gen(randev());
	uniform_real_distribution<> dis(0, 1);

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
	int wintile;
	int endtile;

	//token motion
	int moves;
	bool player = true;
	int randomValue = 0;

	//boardsize input
	cout << "Please enter the number of cells... ";
	cin >> boardsize;

	//total board
	vector<string> topvec = { "+", " - ", "+" };
	vector<string> midvec = { "|", "   ", "|" };
	vector<string> botvec = { "+", " - ", "+" };

	//strings to add to the board
	vector<string> totop = { " - ", "+" };
	vector<string> tomid = { "   ", "|" };
	vector<string> tobot = { " - ", "+" };

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

	int vecplace = 3;

	for (int count2 = 0; count2 < boardsize-2; count2++)
	{
		int temp = static_cast <unsigned int>(steprand(boardsize)); //stores rand value
		string strtemp1 = to_string(temp);
		string strtemp2 = strtemp1;
		string strtemp3 = strtemp1;

		if (tilerand() == true)
		{
			if (strtemp1.front() = '-')
			{
				midvec[vecplace] = strtemp2 + ' ';
			}
			if (strtemp1.length() <= 1)
			{
				midvec[vecplace] = ' ' + strtemp2 + ' ';
			}
			if (strtemp1.length() >= 3)
			{
				midvec[vecplace] = strtemp2;
			}

		}
		else
		{
			midvec[vecplace] = "   ";
		}

		vecplace += 2;
	}

	//inserts token to start
	midvec[tplace] = " @ ";

	//prints the board
	if(boardsize%2==1)
	{
	cout<< "Enter a value from 1 to " << ceil(boardsize/2)+1<<endl;
	}
	else
	{
	cout<< "Enter a value from 1 to " << ceil(boardsize/2)<<endl;
	}
	vprint(topvec);
	cout << endl;
	vprint(midvec);
	cout << endl;
	vprint(botvec);
	cout << endl;

	//initiliaze winning tile
	wintile = (boardsize * 2) - 1;
	//intiliaze replacement outside loop
	string curhold = "   ";
	string futhold;

	while (winner != 1)
	{
		//input movement
		if(player == true)
		{
			cout << "a> ";
			cin >> moves;
			while(cin.fail())
			{
			cout << "Invalid input. Please enter a positive integer."<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
            		cout << "a> ";
			cin >> moves;
			}
			while(moves > ceil(boardsize/2)+1)
			{
				if(boardsize%2==1)
				{
				cout<< "Please enter a POSITIVE integer less than " << ceil(boardsize/2)+2<<endl;
				cout << "a> ";
				cin >> moves;
				}
				else
				{
				cout<< "Please enter a POSITIVE integer less than " << ceil(boardsize/2)<<endl;
				cout << "a> ";
				cin >> moves;
				}
			}
			while(moves < 1)
			{
				if(boardsize%2==1)
				{
				cout<< "Please enter a POSITIVE integer less than " << ceil(boardsize/2)+2<<endl;
				cout << "a> ";
				cin >> moves;
				}
				else
				{
				cout<< "Please enter a POSITIVE integer less than " << ceil(boardsize/2)<<endl;
				cout << "a> ";
				cin >> moves;
				}
			}
			player = false;
		}
		else
		{
			cout << "b> ";
			cin >> moves;
			while(cin.fail())
			{
			cout << "Invalid input. Please enter a positive integer."<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
            		cout << "b> ";
			cin >> moves;
			}
			while(moves > ceil(boardsize/2)+1)
			{
				if(boardsize%2==1)
				{
				cout<< "Please enter a POSITIVE integer less than " << ceil(boardsize/2)+2<<endl;
				cout << "b> ";
				cin >> moves;
				}
				else
				{
				cout<< "Please enter a POSITIVE integer less than " << ceil(boardsize/2)<<endl;
				cout << "b> ";
				cin >> moves;
				}
			}
			while(moves < 1)
			{
				if(boardsize%2==1)
				{
				cout<< "Please enter a POSITIVE integer less than " << ceil(boardsize/2)+2<<endl;
				cout << "b> ";
				cin >> moves;
				}
				else
				{
				cout<< "Please enter a POSITIVE integer less than " << ceil(boardsize/2)<<endl;
				cout << "b> ";
				cin >> moves;
				}
			}
			player = true;
		}

		//bounceback movement
		if ((tplace + (2 * moves)) < 1) {
			future = tplace + 2*moves;
			if (midvec[future] == "   ")
			{
			midvec[tplace] = curhold;
			tplace = (((tplace + (2 * moves)) * -1) + 2);
			futhold = midvec[tplace];
			curhold = futhold;
			midvec[tplace] = " @ ";
			}
			else{
			midvec[tplace] = curhold;
			tplace = (((tplace + (2 * moves)) * -1) + 2);
			tplace = tplace +2*stoi(midvec[future]);
			futhold = midvec[tplace];
			curhold = futhold;
			midvec[tplace] = " @ ";
			}
		}
		else if ((tplace + (2* moves)) > (midvec.size() - 2))
		{	
			future = tplace + 2*moves;
			if (midvec[future] == "   ")
			{
			midvec[tplace] = curhold;
			tplace = (midvec.size() - 2)-(tplace + (2 * moves));
			futhold = midvec[tplace];
			curhold = futhold;
			midvec[tplace] = " @ ";
			}
			else{
			midvec[tplace] = curhold;
			tplace = (midvec.size() - 2)-((tplace + (2 * moves))- (midvec.size() - 2));
			tplace = tplace+2*stoi(midvec[future]);
			futhold = midvec[tplace];
			curhold = futhold;
			midvec[tplace] = " @ ";
			}
		}
		else
		{
			future = tplace + 2*moves;
			if (midvec[future] == "   ")
			{
			midvec[tplace] = curhold;
			tplace += (2 * moves);
			futhold = midvec[tplace];
			curhold = futhold;
			midvec[tplace] = " @ ";
			}
			else{
			midvec[tplace] = curhold;
			tplace += (2 * moves);
			tplace = tplace+2*stoi(midvec[future]);
			futhold = midvec[tplace];
			curhold = futhold;
			midvec[tplace] = " @ ";
			}
		}


		//prints the board
		vprint(topvec);
		cout << endl;
		vprint(midvec);
		cout << endl;
		vprint(botvec);
		cout << endl;

		if (midvec.at(wintile) == " @ ")
		{
			winner = 1;
		}
		else
		{
			winner = 0;
		}

	}

	if (player == false)
	{
		cout << "Player a wins.";
	}
	else
	{
		cout << "Player b wins.";
	}

	//pause buffer
	cin >> pbuffer;

	return EXIT_SUCCESS;
}

//------------------TESTCODES------------------------------

//calls the rand functions for testing
/*
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
*/


//rand value inside tiles
/*
if (tilerand() == true) {
randomValue = steprand(boardsize);
}
else {
randomValue = 0;
}
*/

//psuedo move code
/*
while (moves != 0)
{
midvec[tplace] = " ";
tplace += 2;

//bounceback condition
/*
if ()
{

}

//end of bounceback

midvec[tplace] = "@";
moves--;
}


midvec[tplace] = " ";
tplace += (2 * moves);
midvec[tplace] = "@";
*/
