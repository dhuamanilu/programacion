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
    string s;
    cin>>s;
    ll n=s.size();
    ll ans=LONG_LONG_MIN;
    FOR(i,0,10){
        char c=char('0'+i);
        ll cont=0;
        FOR(j,0,n){
            if(s[j]==c) cont++;
        }
        ans=max(ans,cont);
    }
    FOR(i,0,10){
        char c1=char('0'+i);
        FOR(j,0,10){
            if(i==j) continue;
            char c2=char('0'+j);
            ll cont=0;
            FOR(k,0,n){
                if(cont%2){
                    if(s[k]==c2) cont++;
                }
                else{
                    if(s[k]==c1) cont++;
                }
            }
            if(ans%2==1) ans--;
            ans=max(ans,cont);
        }
    }
    cout<<n-ans<<"\n";

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








