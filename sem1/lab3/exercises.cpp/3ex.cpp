#include <iostream>
using namespace std;

int main()
{
double x,y ;
cout << "x: " ;
cin >> x;
if (x < 0)
{
    y = -1;
}
else if (x == 0)
{
    y = 0;
}
else
{
    y = 1;
}
cout << y << endl;
return 0;

}