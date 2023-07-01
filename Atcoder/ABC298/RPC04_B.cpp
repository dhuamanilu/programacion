#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
typedef priority_queue<ll> pq;
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
#define n_l '\n'
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n;
    cin>>n;
    vll x(n),y(n);
    FOR(i,0,n){
        cin>>x[i]>>y[i];
    }
    double ans=DBL_MIN;
    FOR(i,1,n-1){
        double m=1.0*y[i]/(x[i]-x[0]),m2=1.0*y[i]/(x[i]-x[n-1]);
        double theta=atan(m),theta2=atan(m2);
        double enGrados=theta*(180.0/3.141592653589793238463),enGrados2=theta2*(180.0/3.141592653589793238463);
        //cout<<m2<<" "<<theta2<<" "<<enGrados2<<"\n";
        ans=max(ans,abs(enGrados));
        ans=max(ans,abs(enGrados2));
    }
    cout<<fixed<<setprecision(7)<<ans<<"\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}








