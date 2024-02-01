#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

void readData(int min, int max, int& n) 
{
    cout << "Enter your guess between " << min << " and " << max << "): ";
    cin >> n;
}

void guess(int n, int final_num) 
{
    if (n > final_num) 
    {
        cout << "The number is lower. Try again." << endl;
    }
    else if (n < final_num) 
    {
        cout << "The number is higher. Try again." << endl;
    }
    else 
    {
        cout << "Yes, the searched number is: " << n << endl;
    }
}

int main() {
    int min_range, max_range, n;
    
    cout << "Enter the minimum and maximum values for the range: ";
    cin >> min_range >> max_range;
    
    if (min_range >= max_range) {
        cout << "Invalid range. The minimum value must be less than the maximum value." << endl;
        return 1;
    }

    srand(time(0));
    int final_num = RandomNumber(min_range, max_range);

    cout << "Guess the number between " << min_range << " and " << max_range << "." << endl;

    while (true) {
        readData(min_range, max_range, n);
        guess(n, final_num);

        if (n == final_num) {
            break;
        }
    }

    return 0;
}
