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
    ll x,y,n;
    cin>>x>>y>>n;
    ll a[6];
    a[0]=x;
    a[1]=y;
    FOR(i,2,6){
        a[i]=(a[i-1]-a[i-2]);
        a[i]+=MOD;
        a[i]%=MOD;
    }
    if(a[(n-1)%6]<0){
        a[(n-1)%6]+=MOD;
    }
    cout<<a[(n-1)%6]%MOD<<"\n";
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








