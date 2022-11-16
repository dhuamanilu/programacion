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
    vector <pair<ll,ll>> a(n);
    FOR(i,0,n){
        ll auxi;
        cin>>auxi;
        a[i].f=auxi;
    }
    vector <ll> v;
    FOR(i,0,n){
        ll auxi;
        cin>>auxi;
        a[i].se=auxi;
        v.push_back(a[i].f+a[i].se);
        v.push_back(a[i].f-a[i].se);
    }
    sort(all(v));
    cout<<fixed<<setprecision(10)<<0.5*(v[0]+v[v.size()-1])<<"\n";




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








