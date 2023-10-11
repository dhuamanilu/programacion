#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    i64 pos;
    std::cin >> pos;
    pos--;
    int x, y;
    for (int i = 0; i < n; i++) {
        int len = n - i;
        if (pos < len) {
            x = i;
            y = pos;
            break;
        }
        pos -= len;
    }
    std::cout<<"Este es pos :"<<pos<<std::endl;
    std::string t;
    for (auto c : s) {
        while (x > 0 && !t.empty() && c < t.back()) {
            t.pop_back();
            x--;
        }
        t += c;
    }
    std::cout << t[y];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(10);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    std::cout << "\n";

    return 0;
}
