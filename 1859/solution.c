#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
  ll m, k , a1, ak; cin >> m >> k >> a1 >> ak;
  ll ans = 1e9;
  for(int i = m/k - 1; i <= m/k; i++){
    ll dek = i;
    ll de1 = m - dek*k;
    ll ele1 = (a1 - de1 >= 0 ? 0: abs(a1 - de1));
    ll elek = (ak - dek >= 0 ? 0: abs(ak - dek));
    if(ele1 == 0){
      ll noUsados = a1 - de1;
      if(elek != 0)
        elek -= noUsados/k;
      if(elek < 0)
        elek = 0;
    }
    ans = min(ans, ele1 + elek);
  }cout << ans << endl;
}

int main (){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
