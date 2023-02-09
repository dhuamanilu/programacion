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
    vll cont(5,0);
    vector<string> v;
    FOR(i,0,n){
        string s;
        cin>>s;
        v.pb(s);
    }
    ll ans=LONG_LONG_MIN;
    FOR(i,0,5){
        char ac=char('a'+i);
        vll gana;
        FOR(j,0,n){
            ll cont=0;
            for(char e : v[j]){
                if(e==ac) cont++;
                else cont--;
            }
            gana.pb(cont);
        }
        sort(all(gana),greater<ll>());
        ll su=0,guarda=0;
        FOR(k,0,n){
            su+=gana[k];
            if(su>0) guarda++;
        }
        ans=max(ans,guarda);
    }
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








