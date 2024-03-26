#include <iostream>
using namespace std;

int find_Min(int n)
{
    static int min = n;
    if (n < min)
    {
        min = n;
    }

    return min;
}
int find_Max(int n)
{
    static int max = n;
    if (n > max)
    {
        max = n;
    }
    return max;
}
int main()
{
    int i;
    do
    {
        cin >> i;
        cout << "min number is " << find_Min(i) << endl;
        cout << "max number is " << find_Max(i) << endl;
    } 
    while (i != 0);
    return 0;
}