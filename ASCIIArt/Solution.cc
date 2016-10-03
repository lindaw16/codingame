#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);

    for (int row = 0; row < H; row++) {
        string ROW;
        getline(cin, ROW);

        string text = "";
        for (char& c: T) {
            // If the letter is not part of the alphabet, set it to the index of "?"
            int letter = isalpha(c) ? tolower(c) - 'a' : 26;
            text += ROW.substr(letter*L, L);
        }

        cout << text << endl;
    }
}
