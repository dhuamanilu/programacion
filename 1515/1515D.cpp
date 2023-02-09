#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
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
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    vll c(n);
    FOR(i,0,n){
        cin>>c[i];
        c[i]--;
    }
    vll L(n,0),R(n,0);
    FOR(i,0,l){
        L[c[i]]++;
    }
    FOR(i,l,n){
        R[c[i]]++;
    }
    ll ans=n;
    FOR(i,0,n){
        ll mini=min(L[i],R[i]);
        ans-=2*mini;
        L[i]-=mini;
        R[i]-=mini;
        l-=mini;
        r-=mini;
    }
    ll limit=abs(r-l)/2,have=0;
    if(l<r){
        FOR(i,0,n){
            have+=R[i]/2;
        }
    }
    else{
        FOR(i,0,n){
            have+=L[i]/2;
        }
    }
    ans-=min(have,limit);
    ans-=min(l,r);
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








