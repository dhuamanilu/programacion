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
inline ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
inline ll LCM(ll x,ll y){
	return x/gcd(x,y)*y;
}
void solve(){
    ll n;
    cin>>n;
    ll ans=0,lc=1;
    FOR1(i,1,n){
        lc=LCM(lc,i);
        if(lc>n) break;
        ans+=n/lc;
        ans%=MOD;
    }
    cout<<(ans+n)%MOD<<"\n";

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








