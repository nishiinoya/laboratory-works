#include <iostream>
using namespace std;

int main() {
    int d;
    while (true)
    {
        cout << "Decimal integer (1 to exit): ";
        cin >> d;

        if (d == 1) 
        {
            cout << "Character for ASCII code " << d << " is '" << char(d) << "'" << endl;
            break;
        }
        if (d < 0 || d > 127)
        {
            cout << "Error" <<endl;
        } 
        else 
        {
            cout << "Character for ASCII code " << d << " is '" << char(d) << "'" << endl;
        }
    }

    return 0;
}
