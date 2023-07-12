#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> nails;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            nails.push_back(make_pair(a, b));
        }

        sort(nails.begin(), nails.end(), greater<pair<int, int>>());

        int cut_ropes = 0;
        int highest_nail_height = nails[0].first;

        for (int i = 1; i < n; i++) {
            if (nails[i].second < highest_nail_height - nails[i].first) {
                cut_ropes++;
            } else {
                highest_nail_height = nails[i].first;
            }
        }

        cout << cut_ropes << endl;
    }

    return 0;
}
