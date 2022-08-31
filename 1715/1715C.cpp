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
    ll n,m;
    cin>>n>>m;
    vector <ll> a(n+2,0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ind=0,x=0,res=0;
    for (ll i=1;i<=n;i++) {
        res+=(a[i]!=a[i+1])*(n-(i+1)+1)*i;
    }

    for(ll j=1;j<=m;j++){
        cin>>ind>>x;
        res-=(a[ind-1]!=a[ind])*(n-ind+1)*(ind-1);
        res-=(a[ind]!=a[ind+1])*(n-ind)*ind;
        a[ind]=x;
        res+=(a[ind-1]!=a[ind])*(n-ind+1)*(ind-1);
        res+=(a[ind]!=a[ind+1])*(n-ind)*ind;
        cout<<res+n*(n+1)/2<<"\n";
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








