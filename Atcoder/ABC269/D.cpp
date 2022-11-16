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

vector <vector <ll> > vis(2022,vector <ll> (2022,0));
ll dx[]={-1,-1,0,0,1,1};
ll dy[]={-1,0,-1,1,0,1};
bool isValid(ll a,ll b){
    return a>0 && a<2010 && b>0 && b<2010;
}
void dfs(ll x,ll y){
    vis[x][y]=0;
    for(ll j=0;j<6;j++){
        ll nx=x+dx[j],ny=y+dy[j];
        if(!isValid(nx,ny)) continue;
        if(vis[nx][ny]==0) continue;
        dfs(nx,ny);
    }
}
void solve(){
    ll n;
    cin>>n;
    vector <ll> v1(n),v2(n);
    FOR(i,0,n){
        cin>>v1[i]>>v2[i];
        v1[i]+=1005;
        v2[i]+=1005;
        vis[v1[i]][v2[i]]=true;
    }
    ll ans=0;
    FOR(i,0,n){
        if(vis[v1[i]][v2[i]]==0) continue;
        dfs(v1[i],v2[i]);
        ans++;
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
