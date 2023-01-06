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
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll maxi=max(abs(a[0]-a[1]),abs(a[n-1]-a[n-2])),ans=0;
    FOR(i,1,n-1){
        maxi=max(maxi,abs(a[i+1]-a[i])+abs(a[i-1]-a[i])-abs(a[i+1]-a[i-1]));
    }
    FOR(i,0,n-1){
        ans+=abs(a[i+1]-a[i]);
    }
    cout<<ans-maxi<<"\n";




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








