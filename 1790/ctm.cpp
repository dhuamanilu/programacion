#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int a[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        ans += a[1]*max(0, s);
        for (int i = 2; i <= n-1; i++) {
            ans += a[i]*max(0, s);
            s = max(0, s-a[i]);
        }
        ans += a[n]*s;
        cout << ans <<"\n";
    }
    return 0;
}




