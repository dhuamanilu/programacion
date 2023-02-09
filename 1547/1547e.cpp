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
    ll n,k;
    cin>>n>>k;
    vll a(n+1,LONG_LONG_MAX);
    vll pos;
    FOR(i,0,k){
        ll aux;
        cin>>aux;
        pos.pb(aux);
    }
    ll it=0;
    FOR(i,0,k){
        ll aux;
        cin>>aux;
        a[pos[it++]]=aux;
    }
    vll l(n+1,1e10),r(n+2,1e10);
    ll aux=0;
    FOR1(i,1,n){
        aux=min(a[i],l[i-1]+1);
        l[i]=aux;
    }
    for(ll i=n;i>=1;i--){
        aux=min(a[i],r[i+1]+1);
        r[i]=aux;
    }
    FOR1(i,1,n){
        cout<<min(l[i],r[i])<<" \n"[i==n];
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








