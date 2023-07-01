#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> scores(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        char dash;
        cin >> a >> dash >> b;
        scores[i] = make_pair(a, b);
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int a = scores[i].first;
        int b = scores[i].second;
        if ((a+b+1)/2 % 2 == 1) {
            swap(a, b);
        }
        if (a < x || b < y || a > 11 || b > 11 || (a == 11 && b == 11) || (max(x, y) == 11 && make_pair(x, y) != make_pair(a, b))) {
            cout << "error " << i+1 << endl;
            return 0;
        }
        x = a;
        y = b;
    }
    cout << "ok" << endl;
    return 0;
}
