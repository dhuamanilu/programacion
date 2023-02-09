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
vll vis(100,0);
ll k;
ll calc(ll e,ll lleva){
    if(e==0) return 0;
    if(e%k==0) return calc(e/k,lleva+1);
    else if(e%k==1){
        if(!vis[lleva]){
            vis[lleva]=1;
            e--;
            return calc(e,lleva);
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
    return -1;
}
void solve(){
    ll n;
    cin>>n>>k;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    fill(vis.begin(),vis.end(),0);
    FOR(i,0,n){
        if(calc(a[i],0)==-1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

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








