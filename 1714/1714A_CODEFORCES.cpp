#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)

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
    ll n,h=0,m=0,ans=LONG_LONG_MAX;
    cin>>n>>h>>m;
    FOR(i,0,n){
        ll h1,m1;
        cin>>h1>>m1;
        ll x=h*60+m;
        ll y=h1*60+m1;
        ll diff=y-x;
        if(diff<0) diff+=1440;
        ans=min(ans,diff);
    }
    cout<<ans/60<<" "<<ans%60<<"\n";

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








