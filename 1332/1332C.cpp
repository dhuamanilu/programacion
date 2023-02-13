#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
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
    string s;
    cin>>s;
    ll ans=0;
    FOR(i,0,n/2){
        vll cont(26,0);
        ll aux=2;
        cont[s[i]-'a']++;
        cont[s[n-(i+1)]-'a']++;
        for(ll j=i+k;j<n;j+=k){
            cont[s[j]]++;
            aux++;
        }
        auto x=max_element(all(cont));
        ans+=aux-*x;
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








