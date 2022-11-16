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
const int MX = 200005;
const int N=1000+3;
vector <ll> G[MX];
bool dfs(ll a, ll b){
    if(a==b) return true;
    for(auto e : G[a]){
        dfs(a,e);
    }
    return false;
}
void solve(){
    getchar();
    ll n,k;
    cin>>n>>k;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
        G[a[i]].clear();
    }
    FOR(i,0,n-1){
        G[a[i]].emplace_back(a[i+1]);
    }
    ll aj,bj;
    while(k--){
        cin>>aj>>bj;
        if(dfs(aj,bj)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

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








