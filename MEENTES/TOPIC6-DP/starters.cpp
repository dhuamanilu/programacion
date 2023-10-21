//#pragma GCC optimod_intze("O3,unroll-loops")
#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll long long
const ll INF_MUL=1e15;
const ll INF_ADD=1e18;
#define pb push_back
#define mp make_pair
#define nline "\n"
#define f first
#define s second
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<nline;
#else
#define debug(x);
#endif
void _print(ll x){cerr<<x;}
void _print(char x){cerr<<x;}
void _print(string x){cerr<<x;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
//typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const ll MOD=998244353;
const ll MAX=500500;
void solve(){
    ll n; cin>>n;
    ll ans=0;
    vector<ll> a(n+5);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<ll> pref(n+5,0),suff(n+5,0);
    for(ll i=1;i<=n;i++){
        pref[i]=max(pref[i-1],a[i]);
    }
    for(ll i=n;i>=1;i--){
        suff[i]=max(suff[i+1],a[i]);
    }
    for(ll i=2;i<n;i++){
        a[i]=max(a[i],min(pref[i-1],suff[i+1]));
    }
    for(ll i=1;i<=n;i++){
        ans+=a[i];
    }
    cout<<ans<<nline;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif*/
    ll test_cases=1;
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}
