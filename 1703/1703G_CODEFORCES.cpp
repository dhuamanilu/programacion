#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
typedef vector<ll> vll;
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


void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll r=LONG_LONG_MIN,pref=0;
    FOR(i,-1,n){
        if(i>=0) pref+=a[i]-k;
        ll ans=pref;
        for (int j = i + 1, cnt = 0; cnt < 31 && j < n; j++, cnt++) {
            ans += a[j] / (1LL << (cnt + 1));
        }
        r = max(r, ans);
    }
    cout<<r<<"\n";
    cout<<"pruba :"<< (1LL<<5)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*if (fopen("abcd.in", "r")) {
		freopen("billboard.in", "r", stdin);
		freopen("billboard.out", "w", stdout);
    }*/
  	int t=1;
    cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}








