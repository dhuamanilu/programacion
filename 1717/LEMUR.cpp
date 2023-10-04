///////////////////////////////    _LeMur_
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <chrono>
#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <tuple>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

const int N = 300005;
const int inf = 1000 * 1000 * 1000;
const int mod = 998244353;
// mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937 myrand(373);

int t;
int n;
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //freopen("output.txt", "w", stdout);

  cin >> t;
  int testcase = 0;

  while (t--) {
    ++testcase;

    cin >> n;

    for (int i = 1; i < 2 * n; i++) {
      cin >> a[i];
    }

    if (n == 1) {
      printf("Case #%d: 1\n", testcase);
      continue;
    }

    sort(a + 1, a + 2 * n);

    int pat = -1;

    vector <int> sums = {a[1] + a[2 * n - 1], a[1] + a[2 * n - 2], a[2] + a[2 * n - 1]};
    cout << sums[0] << " " << sums[1] << " " << sums[2] << endl;

    for (int s: sums) {
      int it_r = 2 * n - 1;
      int it_l = 1;

      int cur_answ;
      int cnt = 0;

      while (it_l < it_r) {
        if (a[it_l] + a[it_r] == s) {
          --it_r;
          ++it_l;
          continue;
        }

        if (a[it_l] + a[it_r] > s) {
          cur_answ = s - a[it_r];
          --it_r;
          ++cnt;
        } else {
          cur_answ = s - a[it_l];
          ++it_l;
          ++cnt;
        }
      }

      if (cnt == 0) {
        assert(it_l == it_r);
        cur_answ = s - a[it_l];
        cnt = 1;
      }

      if (cnt == 1 && cur_answ > 0) {
        if (pat == -1 || cur_answ < pat) {
          pat = cur_answ;
        }
      }
    }

    printf("Case #%d: %d\n", testcase, pat);
  }
  return 0;
}
