#include <iostream>
using namespace std;

int main()
{
    char c;
    int hex_num;
    
    while (true)
    {
    cout << "char: ";
    cin >> c;
    hex_num = c;
    cout << "Hexadecimal code: " << hex << hex_num << endl;
    if (c == 'q'){
        break;
    }
    }
    return 0;
}