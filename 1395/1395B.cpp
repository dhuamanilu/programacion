#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)
#define FOR1(i, a, b) for (long long i=a; i<=(b); i++)
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
const int N=105;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool vis[N][N];
vector <pair < ll , ll > > ans;
ll n,m;
bool isValid(ll nx, ll ny){
    return nx>=1 && nx<=n && ny>=1 && ny<=m;
}
void dfs(ll a ,ll b){
    ans.push_back(mp(a,b));
    vis[a][b]=true;
    FOR(i,0,4){
        FOR(k,1,201){
            ll nx=a+k*dx[i],ny=b+k*dy[i];
            if(isValid(nx,ny)){
                if(vis[nx][ny]) continue;
                dfs(nx,ny);
            }
        }

    }
}
void solve(){
    ll sx,sy;
    cin>>n>>m>>sx>>sy;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            vis[i][j]=false;
        }
    }
    dfs(sx,sy);
    for(auto e : ans){
        cout<<e.f<<" "<<e.se<<"\n";
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








