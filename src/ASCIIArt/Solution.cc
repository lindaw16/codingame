#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <vector>

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

    unordered_map <char, vector<string>> dictionary;
    string alphabet = "abcdefghijklmnopqrstuvwxyz?";

    for (int row = 0; row < H; row++) {
        string ROW;
        getline(cin, ROW);

        for (int letter = 0; letter < alphabet.length(); letter++) {
            char c = alphabet[letter];
            string text_data = ROW.substr(letter*L, L);
            dictionary[c].push_back(text_data);
        }
    }

    for (int i = 0; i < H; i++) {
        string text = "";

        for (char& c: T) {
            char lowerC = tolower(c);
            text += dictionary.find(lowerC) == dictionary.end() ? dictionary['?'][i] : dictionary[lowerC][i];
        }

        cout << text << endl;
    }
}
