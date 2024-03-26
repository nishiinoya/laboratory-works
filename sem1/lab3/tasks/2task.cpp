#include <iostream>
using namespace std;

int main()
{
    double k,n,x;
    double y = 0;

    cout << "k: ";
    cin >> k;
    cout << "n: ";
    cin >> n;
    cout << "x: ";
    cin >> x;

    for (int i = 1; i <= n; i++ )
        {
            if (k == i)
            {
                continue;
            }
            else
            {
                y += i/(x + 2*i);

                if (x + 2 * i == 0)
                {
                    cout << "error\n";
                    return 1;
                    
                }
            
            }
            
        }
    cout << y <<endl;
    return 0;

}
