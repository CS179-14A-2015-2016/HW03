#include <iostream>

using namespace std;
int x;
int n;
int minNum;
int maxNum;
int moves;
int box;
int turn = 0;
int tokenCell = 1;
int endCell;
int bounce;
int hit;
string lastMove;
const string token="@";
const string border="+-";
const string cell="| ";
bool outOfBounds = false;


void board()
{
    if (turn == 0 || (minNum <= moves && moves <= maxNum))
    {
        cout << tokenCell << endl;                                      /* REMOVE */
        while (box < n) /* top border */
        {
            cout << border;
            ++box;
            
            if (box == n)
            {
                cout << "+" <<endl;
                if (tokenCell == 1)
                {
                    cout << "|" << token;
                    ++box;
                }
            }
        }
        
        while (box < (2*n)) /* cell */
        {
            if (tokenCell == 1)
            {
                cout << cell;
                ++box;
                
                if (box == (2*n))
                {
                    cout << "|" <<endl;
                }
            }
            else
            {
                
                if (outOfBounds == true) /* bouncing */                             /* ISSUE?? */
                {
                    if ((tokenCell + moves) > endCell)
                    {
                        tokenCell = endCell - bounce;
                    }
                    else if ((tokenCell + moves) <= 0)
                    {
                        tokenCell = bounce;
                    }
                    do
                    {
                        cout << cell;
                        ++box;
                    }while (box < endCell + tokenCell-1);
                    cout << "|"<<token;
                    ++box;
                    if( tokenCell == endCell)
                    {
                        cout << "|" <<endl;
                    }
                    else
                    {
                        do
                        {
                            cout << cell;
                            ++box;
                        }while (box < (2*n));
                        if (box == (2*n))
                        {
                            cout << "|" <<endl;
                        }
                    }
                }
                else /* not bouncing */
                {
                    do
                    {
                        cout << cell;
                        ++box;
                    }while (box < n + tokenCell-1);
                    cout << "|" << token;
                    ++box;
                    if( tokenCell == endCell)
                    {
                        cout << "|" <<endl;
                    }
                    else
                    {
                        do
                        {
                            cout << cell;
                            ++box;
                        }while (box < 2*n);
                        if (box == (2*n))
                        {
                            cout << "|" <<endl;
                        }
                    }
                }
            }
        }
        
        while (box < (3*n)) /* bottom border */
        {
            cout << border;
            ++box;
            
            if (box == (3*n))
            {
                cout << "+" <<endl;
                cout << tokenCell << "|" << bounce << "|" << moves <<endl;                     /*REMOVE!!*/
            }
        }
    }
    box = 0;
}

void playerTurn()
{
    if (turn % 2 != 0)
    {
        cout << "a>";
        cin >> moves;
        lastMove = "A";
    }
    else
    {
        cout << "b>";
        cin >> moves;
        lastMove = "B";
    }

}

void game()
{
    endCell = n;
    outOfBounds = false;
    bounce = 0;
    if (!(turn == 0 || (minNum <= moves && moves <= maxNum)))
    {
        cout << moves << " is not within the given range. Please input a move between " << minNum << " and " << maxNum <<endl;
        moves = 0;
        playerTurn();
    }
    else
    {
        if (((tokenCell + moves) <= 0) || ((tokenCell + moves) > endCell))
        {
            outOfBounds = true;
            if ((tokenCell + moves) > endCell)
            {
                hit = abs ((tokenCell + moves) / endCell);
                bounce = abs (((endCell - 1) * hit) - abs(tokenCell + moves) + 2);             /*ISSUE*/
            }
            else if ((tokenCell + moves) <= 0)
            {
                hit = abs ((tokenCell + moves) / endCell);
                bounce = abs (((endCell - 1) * hit) - abs(tokenCell + moves) + 2);             /*ISSUE*/
           }
        }
        else if (outOfBounds == false || tokenCell != 0)
        {
            tokenCell += moves;
        }
        board();
        ++turn;
        if (endCell == tokenCell)
        {
            cout << "Player " << lastMove << " has won!!!" <<endl;
        }
        else
        {
            playerTurn();
        }
    }
}

int main()
{
    cout << "Welcome to the Board Game by Umbrella Corp!" <<endl;
    cout << "1. How to Play" <<endl;
    cout << "2. Start Game" <<endl;
    cout << "3. Exit" <<endl;
    
    do {cin>>x;}
    while (x == 3);
    
    if (x == 1)
    {
        cout << "How to Play" <<endl;
        cout << "1.  A token, marked by @, starts at cell 0." <<endl;
        cout << "2.  The two players take turns moving the tokens a to b cells forward." <<endl;
        cout << "3.  If the player gets out of bounds, the token bounces back with the leftover steps." <<endl;
        cout << "4.  First player to reach the end wins." << endl;
        
        do
        {
            cin >> x;
        }
        while (x == 3);
    }
    
    if (x == 2)
    {
        cout << "Please input" <<endl;
        cout << "<number of cells> <minimum number of moves> <maximum number of moves>" <<endl;
        cin >> n >> minNum >> maxNum;
        
        if (minNum < maxNum && n > 1)
        {
            do
            {
                game();
            }while(endCell != tokenCell);
        }
        
        else
        {
            cout << "The number of cells declared is less than 1 or the minimum number declared is bigger than the maximum number." <<endl;
            cout << "Please input again" <<endl;
            cout << "<number of cells> <minimum number of moves> <maximum number of moves>" <<endl;
            cin >> n >> minNum >> maxNum;
            
            if (minNum < maxNum && n > 1)
            {
                bool win;
                do
                {
                    game();
                }while(!win);
                cout << "Player " << lastMove << " has won!!!" <<endl;
            }

        }
            
        do
        {
            cin >> x;
        }
        while (x == 3);
    }
        
    if (x == 3)
    {
        do
        {
            cin >> x;
        }
        while (x == 3);
            
        system("pause");
    }
        
    
    
    return 0;
}

