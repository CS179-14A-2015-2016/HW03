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
	int lowerlimit;
	int upperlimit;
	
	//advanced mechanics
	int future; //next move index

	//token motion
	int moves;
	bool player = true;

	//boardsize input
	cout << "Please enter the number of cells... ";
	cin >> boardsize;
	while(cin.fail())
	{
	cout << "Invalid input."<<endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Please enter the number of cells... ";
	cin >> boardsize;
	}
	cout << "a>";
	cin >> lowerlimit;
	while(cin.fail())
	{
	cout << "Invalid input."<<endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Please enter a valid integer."<<endl<<"a>";
	cin >> lowerlimit;
	}
	cout << "b>";
	cin >> upperlimit;
	while(cin.fail())
	{
	cout << "Invalid input."<<endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Please enter a valid integer."<<endl<<"b>";
	cin >> upperlimit;
	}
	while(upperlimit < lowerlimit)
	{
	cout << "Please enter a number larger than "<< lowerlimit << "." <<endl<<"b>";
	cin >> upperlimit;
	}
	while(upperlimit>(boardsize/2))
	{
	cout << "Please enter a number no greater than "<< (boardsize/2) << "." <<endl<<"b>";
	cin >> upperlimit;
	}
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
	cout<< "Enter a value from "<<lowerlimit<<" to " << upperlimit<<endl;
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
				cout << "Invalid input."<<endl<< "Enter a value from "<<lowerlimit<<" to " << upperlimit<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "a> ";
				cin >> moves;
			}
			while(moves > upperlimit)
			{
				cout<< "Enter a value from "<<lowerlimit<<" to " << upperlimit<<endl;
				cout << "a> ";
				cin >> moves;
			}
			while(moves < lowerlimit)
			{
				cout<< "Enter a value from "<<lowerlimit<<" to " << upperlimit<<endl;
				cout << "a> ";
				cin >> moves;
			}
			player = false;
		}
		else
		{
			cout << "b> ";
			cin >> moves;
			while(cin.fail())
			{
				cout << "Invalid input."<<endl<< "Enter a value from "<<lowerlimit<<" to " << upperlimit<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "b> ";
				cin >> moves;
			}
			while(moves > upperlimit)
			{
				cout<< "Enter a value from "<<lowerlimit<<" to " << upperlimit<<endl;
				cout << "b> ";
				cin >> moves;
			}
			while(moves < lowerlimit)
			{
				cout<< "Enter a value from "<<lowerlimit<<" to " << upperlimit<<endl;
				cout << "b> ";
				cin >> moves;
			}
			player = true;
		}

		//bounceback movement 
		if ((tplace + (2 * moves)) < 1) 
		{
			midvec[tplace] = curhold;
			tplace = (((tplace + (2 * moves)) * -1) + 2);
			futhold = midvec[tplace];
			curhold = futhold;
			midvec[tplace] = " @ ";
		}
		else if ((tplace + (2* moves)) > (midvec.size() - 2))
		{	
		
			midvec[tplace] = curhold;
			tplace = (midvec.size() - 2)-((tplace + (2 * moves))- (midvec.size() - 2));
			futhold = midvec[tplace];
			curhold = futhold;
			midvec[tplace] = " @ ";
			
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
			else
			{
				midvec[tplace] = curhold;
				tplace += (2 * moves);
				tplace = tplace+2*stoi(midvec[future]);
				if(tplace<1)
				{
				tplace = ((tplace * -1) + 2);
				futhold = midvec[tplace];
				curhold = futhold;
				midvec[tplace] = " @ ";
				}
				else if(tplace > (midvec.size() - 2))
				{
				tplace = (midvec.size() - 2)-((tplace)- (midvec.size() - 2));
				futhold = midvec[tplace];
				curhold = futhold;
				midvec[tplace] = " @ ";
				}
				else
				{
				futhold = midvec[tplace];
				curhold = futhold;
				midvec[tplace] = " @ ";
				}
			}
		}


		//prints the board
		vprint(topvec);
		cout << endl;
		vprint(midvec);
		cout << endl;
		vprint(botvec);
		cout << endl;

		//winnercheck
		if (midvec.at(wintile) == " @ ")
		{
			winner = 1;
		}
		else
		{
			winner = 0;
		}

	}

	//winner display
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
