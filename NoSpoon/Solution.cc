#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;

vector<vector<bool>> grid;
int height;
int width;

string findNextRight(int h, int w) {
    if (w >= width-1) {
        return "-1 -1";
    }

    for (int i = w+1; i < width; i++) {
        if (grid[h][i]) {
            return to_string(i) + " " + to_string(h);
        }
    }

    return "-1 -1";
}

string findNextBottom(int h, int w) {
    if (h >= height-1) {
        return "-1 -1";
    }

    for (int i = h+1; i < height; i++) {
        if (grid[i][w]) {
            return to_string(w) + " " + to_string(i);
        }
    }

    return "-1 -1";
}

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    cin >> width; cin.ignore();
    cin >> height; cin.ignore();

    for (int h = 0; h < height; h++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);

        vector<bool> row(width);

        for (int w = 0; w < width; w++) {
            row[w] = line[w] == '0';
        }

        grid.push_back(row);
    }

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {

            if (grid[h][w]) {
                string next_right = findNextRight(h, w);
                string next_bottom = findNextBottom(h, w);

                cout << w << " " << h << " " << next_right << " " << next_bottom << endl;
            }
        }
    }
}
