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
const int MX = 100005;
const int N=1000+3;
ll r[MX];
double p[MX];
ll a[MX];
void solve(){
    ll n,m;
    cin>>n>>m;
    FOR(i,0,n){
        cin>>a[i];
    }
    FOR(i,0,m){
        cin>>r[i]>>p[i];
    }
    ll last=n-1;
    while(last>=0 && a[last]==last+1){
        last--;
    }
    if(last==-1){
        cout<<"1.000\n";
        return;
    }
    double ans=1.000;
    FOR(i,0,m){
        if(r[i]-1>=last){
            ans*=(1.0000-p[i]);
        }
    }
    cout<<fixed<<setprecision(7)<<1-ans<<"\n";
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








