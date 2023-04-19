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
const int MAXN = 100010;
int x[MAXN],y[MAXN],a[MAXN],degree[MAXN];
int n,m;
void solve(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        degree[i]=0;
        cin>>a[i];
    }

    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
        degree[x[i]]++;
        degree[y[i]]++;
    }
    int ans=INT_MAX;
    if( (m % 2) == 0){
        cout<<"0\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if( (degree[i]% 2) == 1){
            ans=min(ans,a[i]);
        }
    }
    for(int i=1;i<=m;i++){
        if((degree[x[i]] % 2) == 0 && (degree[y[i]] % 2) == 0){
            ans=min(ans,a[x[i]]+a[y[i]]);
        }
    }
    cout<<ans<<"\n";


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
