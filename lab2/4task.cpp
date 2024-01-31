#include <iostream>
using namespace std;


int main()
{
    int n;
    cout << "n: ";
    cin >> n;
    int result;
    result = 1 << 3*n;
    n >= 0 && n <= 10 ? cout << result << endl : cout << "n is out of range\n" ;
    return 0;
}