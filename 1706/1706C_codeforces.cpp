#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;

#define FOR(i, a, b) for (long long i=a; i<(b); i++)
#define FOR2(i, a, b) for (long long i=a; i<(b); i+=2)
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
    ll a[n+1];
    FOR(i,1,n+1){
        cin>>a[i];
    }
    if(n&1){
        ll ans = 0;
        for (int i = 2; i < n; i += 2)
            ans+=max(0ll, max(a[i - 1], a[i + 1]) - a[i] + 1);
        cout <<ans<< "\n";
        return;
    }
    else{
        ll tot=0;
        for (int i=2;i<n;i+=2)
            tot+=max(0ll,max(a[i-1],a[i+1])-a[i]+1);
        ll ans=tot;
        for (int i=n-1;i>1;i-=2) {
            tot-=max(0ll,max(a[i-2],a[i])-a[i-1]+1);
            tot+=max(0ll,max(a[i-1],a[i+1])-a[i]+1);
            ans=min(ans,tot);
        }
        cout<<ans<<"\n";
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
