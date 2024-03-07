#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef LOCAL
#define dbg(...)
#define chk(...)
#define RAYA
#endif

bool myc(const int& a, const int& b) {
  return a > b;
}

void solve() {
  string s;
  cin >> s;

  int letter[26] = {};

  int size = s.size();
  for (int i = 0; i < size; i++) {
    letter[s[i] - 'a']++;
  }

  int response = 100000000;
  for (int i = 0; i < 26; i++) {
    if (letter[i]) {
      int maxi = 0;
      int count = 0;
      int left = 0, right = 0;
      for (int j = 0; j < letter[i]; j++) {
        if (s[right] - 'a' == i) {
          count++;
        }
        right++;
      }
      maxi = count;
      dbg(left, right, count);

      for (int j = right; j < s.size(); j++) {
        if (s[right] - 'a' == i) {
          count++;
        }
        if (s[left] - 'a' == i) {
          count--;
        }
        right++;
        left++;
        dbg(left, right, count);
        maxi = max(maxi, count);
      }
      dbg((char)('a' + i), maxi, letter[i]);

      response = min(response, letter[i] - maxi);
    }
  }

  cout << response << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}








