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
const int MX =1e6+5;
const int N=1000+3;


void solve(){
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    ll b[n][m][10];
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>a[i][j];
            b[i][j][0]=a[i][j];
        }
    }
    for(ll k=1;k<=log2(min(n,m));k++){
        for(ll i=0;i+(1<<k)<=n;i++){
            for(ll j=0;j+(1<<k)<=m;j++){
                b[i][j][k]=min(b[i+(1<<(k-1))][j+(1<<(k-1))][k-1],min(b[i+(1<<(k-1))][j][k-1],min(b[i][j+(1<<(k-1))][k-1],b[i][j][k-1])));
            }
        }
    }

    int l=1;
        int r=min(n,m);
        while(l<r){
            int x=(l+r+1)/2;
            int z=0;
            int p=log2(x);
            for(int i=0;i+x<=n;i++){
                for(int j=0;j+x<=m;j++){
                    if(min(min(b[i][j][p],b[i+x-(1<<p)][j+x-(1<<p)][p]),min(b[i][j+x-(1<<p)][p],b[i+x-(1<<p)][j][p]))>=x){
                        z=1;
                    }
                }
            }
            if(z){
                l=x;
            }
            else{
                r=x-1;
            }
        }
        cout<<l<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








