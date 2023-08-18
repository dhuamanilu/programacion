#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> results;

    for (int i = 0; i < t; ++i) {
        int m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;

        int r = m % k;
        int x = 0, y = 0;

        if (r != 0) {
            x = ceil(static_cast<double>(r) / a1);
            y = ceil(static_cast<double>(k - r) / ak);
        }

        results.push_back(x + y);
    }

    for (int i = 0; i < t; ++i) {
        cout << results[i] << endl;
    }

    return 0;
}
