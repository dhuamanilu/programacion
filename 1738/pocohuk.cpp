#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define dbg(...)
#define chk(...)

#define RAYA


ll mkp(string s, string sub) {
  int ga = sub.size();
  int aux[ga];

  for (int pr = 0; pr < sub.size(); pr++) {
    dbg(pr);
    int pl = pr - 1;
    while (true) {
      dbg(pl);
      if (pl == -1) {
        aux[pr] = 0;
        break;
      } else {
        if (sub[aux[pl]] == sub[pr]) {
          dbg(aux[pr], aux[pl]);
          aux[pr] = aux[pl] + 1;
          break;
        } else {
          dbg(aux[pr]);
          pl = aux[pl] - 1;
        }
      }
    }
  }
  for (int i = 0; i < ga; i++) {
    cout << "que chucha\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;
  s += s;

  cout << mkp(s, t) << "\n";

  return 0;
}