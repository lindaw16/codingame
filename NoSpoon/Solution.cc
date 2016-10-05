#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;

string findNextRight(vector<vector<int>> &grid, int height, int width, int h, int w) {
    if (w >= width-1) {
        return "-1 -1";
    }

    for (int i = w+1; i < width; i++) {
        if (grid[h][i] == 0) {
            return to_string(i) + " " + to_string(h);
        }
    }

    return "-1 -1";
}

string findNextBottom(vector<vector<int>> &grid, int height, int width, int h, int w) {
    if (h >= height-1) {
        return "-1 -1";
    }

    for (int i = h+1; i < height; i++) {
        if (grid[i][w] == 0) {
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
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    vector<vector<int>> grid(height, vector<int>(width));

    for (int h = 0; h < height; h++) {

        string line; // width characters, each either 0 or .
        getline(cin, line);

        for (int w = 0; w < width; w++) {
            if (line[w] == '0') {
                grid[h][w] = 0;
            } else if (line[w] == '.') {
                grid[h][w] = 1;
            }
        }
    }

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {

            if (grid[h][w] == 0) {
                string next_right = findNextRight(grid, height, width, h, w);
                string next_bottom = findNextBottom(grid, height, width, h, w);

                cout << w << " " << h << " " << next_right << " " << next_bottom << endl;
            }
        }
    }
}
