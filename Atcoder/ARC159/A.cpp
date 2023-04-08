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

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> a(n,vector<ll>(n,(ll)1e15));
    FOR(i,0,n){
        FOR(j,0,n){
            cin>>a[i][j];
            if(!a[i][j]){
                a[i][j]=1e15;
            }
        }
    }
    FOR(k,0,n){
        FOR(i,0,n){
            FOR(j,0,n){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    ll q;
    cin>>q;
    FOR(i,0,q){
        ll s,t;
        cin>>s>>t;
        s--;
        t--;
        if(a[s%n][t%n]<=n)
            cout<<a[s%n][t%n]<<"\n";
        else{
            cout<<"-1\n";
        }
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
