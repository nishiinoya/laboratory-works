#include <iostream> 
using namespace std;

int main() 
{
  int n; 
  cout << "number: "; 
  cin >> n; 
  255 > n && n > 32 ? cout << "ASCII Code of number " << n << " is " << char(n) << endl : (cout << "n is out of range" << endl); 
  return 0;
}
