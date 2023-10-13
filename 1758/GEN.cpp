#include <bits/stdc++.h>

using namespace std;

signed main() {
    const int t = 10000;
    cout << t << "\n";

    const int n = 25;
    const int m = 1;

    for(int i = 0; i < t; i++) {
        cout << n << " " << m << "\n";

        string x = "";
        for(int j = 0; j < n; j++) {
            x += char('a' + j);
        }
        string s = "z";

        cout << x << "\n";
        cout << s << "\n";
    }
    return 0;
}








