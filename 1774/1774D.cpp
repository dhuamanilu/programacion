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
    vector <vector <ll> > a(n,vector <ll>(m));
    vector <ll> diff;
    ll total=0;
    FOR(i,0,n){
        ll cont=0;
        FOR(j,0,m){
            cin>>a[i][j];
            cont+=a[i][j];
        }
        total+=cont;
        diff.push_back(cont);
    }
    if(total%n!=0){
        cout<<"-1\n";
    }
    else{
        ll prom=total/n;
        ll ans=0;

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








