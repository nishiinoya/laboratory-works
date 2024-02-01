#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int counter, reverse_counter;
    counter = 0;
    int input_limit = 80;
    char str[input_limit];
    cin.getline(str, input_limit);

    int length = strlen(str);
    reverse_counter = length - 1;
    while (counter < length)
    {
        

        // cout << "Cycle " << i << " Comparing " << str[i] << " and " << str[k] << endl;

        if (str[counter] != str[reverse_counter])
        {
            if (str[counter] == ' ')
            {
                counter++;
            }
            else if (str[reverse_counter] == ' ')
            {
                reverse_counter--;
            }
            else
            {

                cout << "\033[1;31mNot a palindrome\033[0m\n";
                return 1;
            }
        }
        else
        {
            reverse_counter--;
            counter++;
        }
    }
 cout << "\033[1;32mIs a palindrome\033[0m\n";
 
    return 0;
}
