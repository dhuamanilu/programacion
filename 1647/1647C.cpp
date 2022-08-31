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
    FOR(i,0,n){
        string s;
        cin>>s;
        FOR(j,0,m){
            a[i][j]=s[j]-'0';
        }
    }
    if(a[0][0]==1){
        cout<<"-1\n";
        return;
    }
    vector<array<ll,4>> ans;
    for (int j = m - 1; j >= 0; --j) {
        for (int i = n - 1; i >= 0; --i) {
            if (a[i][j]) {
                if (i != 0) {
                    ans.push_back({i, j + 1, i + 1, j + 1});
                } else {
                    ans.push_back({i + 1, j, i + 1, j + 1});
                }
            }
        }
    }
    cout<<ans.size()<<"\n";
    FOR(i,0,ans.size()){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<"\n";
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








