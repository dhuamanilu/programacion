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
const int MOD2=998244353;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    ll b[n];
    FOR(i,0,n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n,greater <ll>());
    ll res1=0;

    FOR(i,0,k){
        res1+=b[i];
    }
    ll res2=1;
    ll guarda=-1;
    FOR(i,0,n){
        if(a[i]>=n-k+1){
            res2%=MOD2;
            if(guarda!=-1){
                res2*=(i-guarda)%MOD2;
            }
            res2%=MOD2;
            guarda=i;
        }
    }
    cout<<res1<<" "<<res2<<"\n";
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








