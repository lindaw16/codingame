#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ctype.h>

using namespace std;


string toLowerCase(string input) {
    string lower = input;
    for (int i = 0; i < input.length(); i++) {
        lower[i] = tolower(lower[i]);
    }
    return lower;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();

    std::unordered_map <string, string> extToMime;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();

        //string lowerEXT = toLowerCase(EXT);
        //extToMime[lowerEXT] = MT;

        transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        extToMime[EXT] = MT;
    }


    /*
    // Print out each key/value pair in the map
    for (auto i = extToMime.begin(); i != extToMime.end(); ++i) {
        cerr << "key: " << i->first << "\t" << "value: " << i->second << endl;
    }
    */

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // For each of the Q filenames, display on a line the corresponding MIME type.
    // If there is no corresponding type, then display UNKNOWN.

    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);

        cerr << FNAME << endl;

        string::size_type idx = FNAME.rfind(".");

        if (idx != std:: string::npos) {
            string extension = FNAME.substr(idx+1);
            string lowerExt = toLowerCase(extension);

            if (extToMime.find(lowerExt) != extToMime.end()) {
                cout << extToMime[lowerExt] << endl;
                continue;
            }
        }
        cout << "UNKNOWN" << endl;
    }
}
