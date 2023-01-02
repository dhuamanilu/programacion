#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
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
const int N=1000+3;
ll n;
bool isValid(ll x,ll y){
    return x>=0 && x<n && y>=0 && y<n;
}
void solve(){
    cin>>n;
    ll a[n];
    vector <vector<ll>> vis(n,vector <ll> (n,-1));
    FOR(i,0,n){
        cin>>a[i];
        vis[i][i]=a[i];
    }
    FOR(i,0,n){
        ll x=i;
        ll y=i;
        FOR(j,1,a[i]){
            if(y>0 && vis[x][y-1]==-1){
                y--;
            }
            else{
                x++;
            }
            vis[x][y]=a[i];
        }
    }
    FOR(i,0,n){
        FOR(j,0,i+1){
            cout<<vis[i][j]<<" ";
        }
        cout<<"\n";
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








