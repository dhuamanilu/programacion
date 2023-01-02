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
    ll n,q;
    cin>>n>>q;
    //GRUPO 3 todos los intervalos cuestan lo mismo
    vector < pair<ll,ll> > a;
    FOR(i,0,q){
        ll l,r,c;
        cin>>l>>r>>c;
        //ignorar c ya que es 1
        a.push_back(mp(l,r));
    }
    sort(all(a));
    a.push_back(mp(LONG_LONG_MAX,LONG_LONG_MAX));
    ll s=1,e=0;
    ll ans=0;
    ll i=0;
    while(i<a.size()){
        if(a[i].f<=s){
            e=max(e,a[i].se);
            i++;
        }
        else{
            s=e;
            ans++;
            if(a[i].f>e || e>=n) break;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








