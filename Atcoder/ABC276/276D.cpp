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

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll ans=0,g=0;

    FOR(i,0,n){
        g=__gcd(g,a[i]);
    }

    FOR(i,0,n){
        a[i]/=g;
        while(a[i]%2==0){
			a[i] /= 2;
			ans++;
		}
		while(a[i]%3==0){
			a[i] /= 3;
			ans++;
		}
		if(a[i]!=1){
            cout<<"-1\n";
            return;
		}
    }
    cout<<ans<<"\n";

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
