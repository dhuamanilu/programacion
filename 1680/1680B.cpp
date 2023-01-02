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
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    ll px=LONG_LONG_MAX,py=LONG_LONG_MAX;
    FOR(i,0,n){
        string s;
        cin>>s;
        FOR(j,0,m){
            a[i][j]=(s[j]=='R');
            if(a[i][j] && i<=px && j<=py){
                px=i;
                py=j;
            }
        }
    }
    FOR(i,0,n){
        FOR(j,0,m){
            if(a[i][j]){
                if(i-px >= 0 && j-py>=0){
                    continue;
                }
                else{
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";

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








