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
const int N=1000+3;

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector <bool> a(n+1);
    vector <ll> cost(n+1);
    FOR(i,0,n){
        a[i+1]=(s[i]=='1');
    }
    for(ll i=n;i>=1;i--){
        for(ll j=i;j<=n;j+=i){
            if(a[j]) break;
                cost[j]=i;
        }
    }
    ll ans=0;
    FOR1(i,1,n){
        if(!a[i])
            ans+=cost[i];
    }
    cout<<ans<<"\n";

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








