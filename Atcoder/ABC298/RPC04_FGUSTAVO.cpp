#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

map<string, int> angles = {{"N", 0}, {"E", 90}, {"S", 180}, {"W", 270}, {"NE", 45}, {"SE", 135}, {"SW", 225}, {"NW", 315}};

int getAngle(string dir) {
    if (angles.find(dir) != angles.end()) {
        return angles[dir];
    }
    string sub_dir = dir.substr(dir.length()-2);
    int angle1 = getAngle(sub_dir);
    int angle2 = getAngle(sub_dir.substr(0, 1));
    return (angle1 + angle2) / 2;
}

double smallestTurn(string x, string y) {
    int angleX = getAngle(x);
    int angleY = getAngle(y);
    double diff = angleY - angleX;
    if (diff < -180) diff += 360;
    if (diff > 180) diff -= 360;
    if (abs(diff) <= 180) {
        return abs(diff);
    }
    return 360 - abs(diff);
}

int main() {
    string x, y;
    cin >> x >> y;
    double ans = smallestTurn(x, y);
    cout.precision(10);
    cout << fixed << ans << endl;
    return 0;
}
