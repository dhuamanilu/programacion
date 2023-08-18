#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
  ll m, k , a1, ak; cin >> m >> k >> a1 >> ak;
  ll dek = m/k;
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
  cout << ele1 + elek << endl;
}

int main (){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("entrada.txt","r",stdin);
  freopen("salida.txt","w",stdout);
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
