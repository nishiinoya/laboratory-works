#include <iostream>
using namespace std;
int main() 
{
    int k, m, n;

    cout << "k: ";
    cin >> k ;
    cout << "m: " ;
    cin >> m;
    cout << "n: ";
    cin >> n;
    int bit_m = (k >> m) & 1;
    int bit_n = (k >> n) & 1;
    int change = (1 << m) | (1 << n);
    
    (bit_m != bit_n) ? k ^= change  : k |= k ;

    k < 0 || m < 0 || m >= 32 || n < 0 || n >= 32 ? cout << "Invalid values\n" : cout << k << endl;
    return 0;
}

