#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
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
const int MX = 100005;
const int N=1000+3;
vector <ll> divi[MX];
void precalc(){
    FOR1(i,1,1e5){
        for(ll j=i;j<=1e5;j+=i){
            divi[j].pb(i);
        }
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vpll a(n);
    FOR(i,0,n){
        cin>>a[i].f;
        a[i].se=i;
    }
    sort(all(a));
    ll curr=0,j=0;
    vll frec(m+5,0);
    ll ans=LONG_LONG_MAX;
    FOR(i,0,n){
        for(auto e : divi[a[i].f]){
            if(e>m){
                break;
            }
            if(!frec[e]++){
                curr++;
            }
        }
        while(curr==m){
            ll diff=a[i].f-a[j].f;
            ans=min(ans,diff);
            for(auto e : divi[a[j].f]){
                if(e>m) break;
                if(--frec[e]==0){
                    curr--;
                }
            }
            j++;
        }
    }
    if(ans==LONG_LONG_MAX){
        ans=-1;
    }
    cout<<ans<<"\n";


}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    precalc();
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








