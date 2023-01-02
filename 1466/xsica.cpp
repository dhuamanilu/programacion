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
static bool compy (pair<ll,ll > a,pair<ll, ll > b){
    if(a.f==b.f) return a.se>b.se;
    else return b.f>a.f;
}
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
    sort(a.begin(),a.end(),compy);
    ll ans=1,r=a[0].se;
    FOR(i,0,a.size()){
        if(r==n) break;
        ll maxiR=r,j=i+1;
        while(j<a.size()){
            if(a[j].f<=r){
                maxiR=max(maxiR,a[j].se);
            }
            else break;
            j++;
        }
        i=j-1;
        r=maxiR;
        //cuesta 1
        ans++;
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
