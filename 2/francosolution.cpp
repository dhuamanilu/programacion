#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

void solve(){
  ll x, y, n; cin >> x >> y >> n;
  ll sum = (n - 1)*n/2;
  string ans = "";
  if(sum <= y - x){
    ll acum = 0;
    for(int i = 0; i < n - 1; i++){
      acum += i;
      ans = " " + to_string(y - acum) + ans;
    }cout << x << ans << nl;
  }else{
    cout << "-1" << nl;
  }
}

int main (){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt","r",stdin);
  freopen("ouput.txt","w",stdout);
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
