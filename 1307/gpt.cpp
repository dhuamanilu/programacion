#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int max_a = *max_element(a.begin(), a.end());
        int max_b = *max_element(b.begin(), b.end());
        if (max_a != max_b) {
            cout << "NO" <<"\n";
        } else {
            vector<int> idx_a, idx_b;

            for (int i = 0; i < n; i++) {
                if (a[i] == max_a) {
                    idx_a.push_back(i);
                }

                if (b[i] == max_b) {
                    idx_b.push_back(i);
                }
            }

            if (idx_a == idx_b) {
                cout << "YES" <<"\n";
            } else {
                cout << "NO" <<"\n";
            }
        }
    }

    return 0;
}
