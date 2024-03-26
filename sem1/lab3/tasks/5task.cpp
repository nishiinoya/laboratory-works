#include <iostream>
using namespace std;

int main()
{
    double x1, x2, s, y, p;
    int n;

    cout << "n: ";
    cin >> n;
    cout << "x1, x2: ";
    cin >> x1 >> x2;
    cout << "step: ";
    cin >> s;

    if (s <= 0 ){
        cout << "incorrect data\n";
    }
    else
    {
        for (y = 0; x1 <= x2; x1 += s)
        {
            if(x1>= 0 && n>= 1)
            { 
            
                for( int i = 0; i < n-1; i++)
                {
                    p = 1; 
                    for (int j = 0; j < n-1; j++)
                    {
                        p = p * (x1 + i + j*j);
                        //cout<<"p:"<<p<<endl;
                        
                    }
                    y += p;
                } 

            }
            else if(x1 < 0 && n >= 4)
            {
                y = 1; 
                for ( int j = 2; j < n-2; j++)
                {
                    y = y*(j + x1);
                }
                
                
            }
            else
            {
                cout << "incorrect data\n" ;
                return 1;
            }
            cout<< "x:"<< x1 << " y:" << y << endl; 
        }  
        
    }

    return 0;

}