#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <vector>
#include <regex>
#include <tuple>
#include <math.h>

using namespace std;

/**
 * @string latlon Of the form "x,xx" representing degrees
 * @return The input degree expressed as a radian in float form
 **/
float convertToRad(string latlon) {
    float degree = stof(latlon.replace(latlon.find(","), 1, "\."));
    return degree * M_PI / 180;
}

tuple<string, float, float> getDefibrillatorInfo(string defib) {
    regex r(";");
    sregex_token_iterator it(defib.begin(), defib.end(), r, -1);
    sregex_token_iterator end;
    vector<string> all_data(it, sregex_token_iterator());

    string name = all_data[1];
    string s_lon = all_data[4];
    float lon = convertToRad(s_lon);

    string s_lat = all_data[5];
    float lat = convertToRad(s_lat);

    return make_tuple(name, lon, lat);
}

float getDistance(float lonA, float latA, float lonB, float latB) {
    float x = (lonB-lonA)*cos((latA+latB)/2);
    float y = latB-latA;
    float d = sqrt(x*x + y*y) * 6371;

    return d;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();

    float myLon = convertToRad(LON);
    float myLat = convertToRad(LAT);
    float closest_defib_distance = numeric_limits<float>::max();
    string closest_defib_name = "";

    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);

        // Get the defribillator's distance and name
        tuple<string, float, float> info = getDefibrillatorInfo(DEFIB);

        float defibLon = get<1>(info);
        float defibLat = get<2>(info);
        float distance = getDistance(myLon, myLat, defibLon, defibLat);

        if (distance < closest_defib_distance) {
            closest_defib_distance = distance;
            closest_defib_name = get<0>(info);
        }
    }

    cout << closest_defib_name << endl;
}
