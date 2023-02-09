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
const int MX = 200005;
const int N=1000+3;
ll a[MX];
bool judge(int n){
    static int used[MX];
    for(int i = 1; i <= n; i++) used[i] = 0;
    for(int i = 0; i < n; i++) used[a[i]] = 1;
    for(int i = 1; i <= n; i++) {
        if(!used[i]) return 0;
    }
    return 1;
}
void check(ll len,ll n,vpll &a){
    if(judge(len) &&judge(n-len)){
        a.pb({len,n-len});
    }
}
void solve(){
    ll n;
    cin>>n;

    ll maxi=LONG_LONG_MIN;
    FOR(i,0,n){
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    vpll ans;
    check(n-maxi,n,ans);
    check(maxi,n,ans);
    cout<<ans.size()<<"\n";
    for(auto e : ans){
        cout<<e.f<<" "<<e.se<<"\n";
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








