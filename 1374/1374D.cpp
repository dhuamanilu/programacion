#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
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
    ll a[n];
    mll m;
    FOR(i,0,n){
        cin>>a[i];
        a[i]%=k;
        if(!a[i]) continue;
        m[k-a[i]]++;
    }
    if(m.empty()){
        cout<<"0\n";
        return;
    }
    ll extra=0,last=0;
    for(auto e : m){
        if(e.se>=extra){
            extra=e.se;
            last=e.f;
        }
    }
    cout<<k*(extra-1)+last+1<<"\n";

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








