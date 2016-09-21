#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>

#include <typeinfo>


using namespace std;

string convertToBinary(int n) {
    return bitset<7>(n).to_string();

    /*
    string r;
    while (n != 0) {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }

    // pad with 0s to make it 7-bit
    if (r.length() < 7) {
        r = string(7-r.length(), '0') + r;
    }
    return r;
    */
}

string convertToChuck(int count, char num) {
    string chuck = num == '0' ? "00" : "0";
    chuck += " " + string(count, '0');
    return chuck;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    string bin_message = "";
    for (char& c : MESSAGE) {
        bin_message += convertToBinary(c);
    }

    string chuck_message = "";
    char current_num = bin_message[0]; // '0' or '1'
    int current_count = 0;

    for (char& c : bin_message) {
        if (c != current_num) {
            chuck_message += convertToChuck(current_count, current_num) + " ";
            current_num = c;
            current_count = 0;
        }

        current_count++;
    }

    chuck_message += convertToChuck(current_count, current_num);

    cout << chuck_message << endl;
}
