#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    map<int, int> counts;             
    set<int> exclusion = {3, 7, 9};

    int values;
    cout << "Enter the number of integer values to input: ";
    cin >> values;

    cout << "Enter " << values << " integer values:" << endl;
    for (int i = 0; i < values; ++i) {
        int num;
        cin >> num;

        // Check if the num is in the exclusion list
        if (exclusion.find(num) != exclusion.end()) {
            cout << "Excluded number encountered: " << num << endl;
        } else {
    
            counts[num]++;
        }
    }

    cout << "\nCounts of each num:" << endl;
    for (const auto &pair : counts) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
