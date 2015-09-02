#include <iostream>
#include <string>
//Ramos Salay
using namespace std;

void board(int n, int token,const int *arr, const int size)
{
    int index = 1;
    token = 2*token + 1;
    for(int i = 0; i<=(n*2); i++)
    {
        if(i % 2 == 0)
            cout<<"+";
        else
            cout<<"-";
    }
    cout<<"\n";
    for(int i = 0; i<=(n*2); i++)
    {
        if(i == token)
        {
            cout<<"@";
        }
        else if(i % 2 == 0)
            cout<<"|";
        else
        {
            if (i % 3 == 0 && i != (n*2)-1)
            {
               
                  cout<< arr[index];
                
                index+=2;

            }
            else
                cout<<" ";
        }
    }
    cout<<"\n";
    for(int i = 0; i<=(n*2); i++)
    {
        if(i % 2 == 0)
            cout<<"+";
        else
            cout<<"-";
    }
    cout<<"\n";
    index = 0;
}

int main()
{
    int n=0,a=0,b=0;
    int token = 0;
    
    while(n <=1)
    {
        cout<<"Input n: " ;
        cin >> n;
    }
    
    while (a <1)
    {
        cout<<"Input a: " ;
        cin >> a;
    }
    //while(b <= a || b>((n/3)+1))
    while(b <= a)
    {
        cout<<"Input b: " ;
        cin >> b;
    }
    int array_size = 20;
    static int arr[20];
    srand((unsigned)time(NULL));
    
    for(int i=0; i<array_size; i++)
    {

        if(i%2!=0)
        {
        arr[i] = rand() % 4 -2;
        }
        else
        {
            arr[i] = 0;
        }
        
        
     
    }
    /*for(int i=0; i<array_size; i++)
    {
        cout << arr[i] << " ";
    }
     */

    cout << "\n";
    board(n,token,arr,array_size);
    bool running = 1,p1turn =1;
    
    while (running) {
        if(token == (n-1))
        {
            if(p1turn)
            {
                cout << "Player 2 wins\n";
                
            }
            else
            {
                cout << "Player 1 wins\n";
            }
            
            running = 0;
        }
        else if(p1turn)
        {
            int p1 = 0,checkp1 =0;
            while(!checkp1)
            {
                
                cout << "P1 turn: ";
                cin >> p1;
                
                
                if(!(p1 <= b && p1 >= a))
                {
                    cout << "Input between " << a << " and "<< b << "\n";
                }
                else
                {
                    checkp1 =1;
                }
                
            }
            token += p1;
          //  cout << "\n TOKEN BEFORE:" << token << "\n";
            int checktile = 2*token + 1;
          //  cout << "\n CHECKTILE TOKEN:" <<  checktile << "\n";
           
            if (checktile % 3 == 0 && checktile != (n*2)-1 )
            {
             //   cout << "\n TILE:" <<  (checktile/3)-1 << "\n";
                token = token + arr[(checktile/3)];
            }
            if (token > n-1)
            {
                token = (n-1) - (token - (n-1));
            }
            else if (token < 0)
            {
                token = 0;
            }
           // cout << "\n TOKEN:" << token << "\n";
            //cout<< "Token current position: " << token <<"\n";
            
            board(n,token,arr,array_size);
            p1turn = 0;
            
        }
        else
        {
            int p2 = 0,checkp2 =0;
            while(!checkp2)
            {
                
                cout << "P2 turn: ";
                cin >> p2;
                
                
                if(!(p2 <= b && p2 >= a))
                {
                    cout << "Input between " << a << " and "<< b << "\n";
                }
                else
                {
                    checkp2 =1;
                }
                
            }
            
            
            token +=p2;
           // cout << "\n TOKEN BEFORE:" << token << "\n";
      
            int checktile = 2*token + 1;
           //  cout << "\n CHECKTILE TOKEN:" <<  checktile << "\n";
            
            if (checktile % 3 == 0 && checktile != (n*2)-1)
            {
                
               // cout << "\n TILE:" <<  (checktile/3)-1 << "\n";
                token = token + arr[(checktile/3)];
            }
            if (token > n-1)
            {
                token = (n-1) - (token - (n-1));
            }
            else if (token < 0)
            {
                token = 0;
            }
           // cout << "\n TOKEN:" << token << "\n";
            
            
            //cout<< "Token current position: " << token <<"\n";
            
            board(n,token,arr,array_size);
            p1turn = 1;
        }
    }
    
    return 0;
}


