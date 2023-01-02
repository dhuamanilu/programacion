#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int t, n, m;
int a[MAXN];

int find_max_l(int i, int j) {
    int l = min(n - i + 1, m - j + 1);
    while (l > 0) {
    bool valid = true;
    for (int x = i; x < i + l && valid; x++) {
        for (int y = j; y < j + l && valid; y++) {
            if (a[x * m + y] < l) {
            valid = false;
            }
        }
    }
    if (valid) {
        return l;
    }
        l--;
    }
    return 0;
}

int main() {
    cin >> t;
    while (t--) {

        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i * m + j];
            }
        }
        int l = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                l = max(l, find_max_l(i, j));
            }
        }
        cout <<l<<"\n";
        }
    return 0;
}
