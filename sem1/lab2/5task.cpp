#include <iostream>
using namespace std;

int main()
{
    double k;
    cout << "k: ";
    cin >> k;
   
    double y = 1/k + 1/(k*k) + 1/(k*k*k);

    k > 0 ?  cout << "y is: " << y << endl : cout << "error\n";
    return 0;
}
