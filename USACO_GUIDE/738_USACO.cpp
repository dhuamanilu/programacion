#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<ll,ll>> vpll;
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
    ll n;
    cin>>n;

    vpll a(n);
    FOR(i,0,n){
        cin>>a[i].se>>a[i].f;
    }
    sort(all(a));
    ll ans=0;
    ll i=0,j=n-1;
    while(i<=j){
        ll mini=min(a[i].se,a[j].se);
        a[i].se-=mini;
        if(i!=j)
            a[j].se-=mini;
        ans=max(ans,a[i].f+a[j].f);
        if(a[i].se==0){
            i++;
        }
        if(a[j].se==0){
            j--;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("pairup.in", "r")) {
		freopen("pairup.in", "r", stdin);
		freopen("pairup.out", "w", stdout);
    }
  	int t=1;
    //cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}








