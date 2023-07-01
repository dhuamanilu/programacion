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
const int MX = 100001;
const int N=1000+3;
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2)%(MOD);
    if (b % 2)
        return (res * res * a) % (MOD);
    else
        return (res * res)%MOD;
}
void solve(){
    ll n;
    cin>>n;
    ll ans=1;
    FOR(i,0,n){
        ans*=2;
        ans%=MOD-1;
    }
    ans-=2;
    ans%=MOD-1;
    ll po=binpow(4,ans);
    po*=6;
    po%=MOD;
    cout<<po<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*if (fopen("abcd.in", "r")) {
		freopen("billboard.in", "r", stdin);
		freopen("billboard.out", "w", stdout);
    }*/
  	int t=1;
    //cin>>t;
  	while(t--){
        solve();
  	}
	return 0;
}
