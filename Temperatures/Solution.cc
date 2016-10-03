#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


int MAX_TEMP = 5526;
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    //getline(cin, temps);

    cerr << temps << endl;

    if (n == 0) {
        cout << 0 << endl;
    } else {
        int minAbsTemp = MAX_TEMP+1;
        int temperature;

        for (int i = 0; i < n; i++) {
            cin >> temperature;
            if (abs(temperature) < abs(minAbsTemp) ||
                (abs(temperature) == abs(minAbsTemp) && temperature > 0)) {
                minAbsTemp = temperature;
            }
        }

        cout << minAbsTemp << endl;
    }
}
