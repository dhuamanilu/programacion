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
const int N=105;
const int INF=100000000;
ll a[N][N];
ll dfs(ll ele,ll ele2){

}
void solve(){
    ll n,k;
    cin>>n>>k;

    FOR(i,0,n){
        FOR(j,0,n){
            cin>>a[i][j];
        }
    }
    ll q;
    cin>>q;
    FOR(i,0,q){
        ll s,t;
        cin>>s>>t;
        s--;
        t--;
        ll dist=dfs(s,t);
    }

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
