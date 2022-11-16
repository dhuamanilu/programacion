#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define mp make_pair
#define pb push_back
#define f first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200005;
const int N=1000+3;
const int INF=100000000;
map <ll,ll> m;
ll f(ll a){
    if(a==0) return 1;
    auto k=m.find(a);
    if(k!=m.end()){
        ll ni=k->second;
        return ni;
    }
    else{
        ll g=f(a/2);
        ll e=f(a/3);
        m.insert(mp(a,g+e));
        return g+e;
    }
}
void solve(){
    ll n;
    cin>>n;
    cout<<f(n)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  	int t=1;
    //cin>>t;
  	while(t--){
        solve();
  	}
	return 0;
}
