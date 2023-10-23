#include <bits/stdc++.h>
using namespace std;
#define ll __int128
#define nl "\n"
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll base10(string &n) {
  ll size = n.size();
  ll ini = 0;
  ll ans = 0;
  for (ll i = size - 1; i >= 0; i--) {
    ans += (n[ini] - '0') * (ll)binpow(8, i);
    ini++;
  }
  return ans;
}

string reemplace(string &curr) {
  for (ll i = 0; i < curr.size(); i++) {
    if (curr[i] == '8')
      curr[i] = '5';
  }
  return curr;
}

string base9(ll n) {
  string ans = "";
  while (n) {
    string curr = to_string(n % 9);
    ans = reemplace(curr) + ans;
    n /= 9;
  }
  return ans;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  string ans = to_string(n);
  if (n == 0) {
    cout << 0 << nl;
    return;
  }
  for (ll i = 0; i < k; i++) {
    ans = base9(base10(ans));
  }
  cout << ans << nl;
}

int main() {
  solve();
  return 0;
}
