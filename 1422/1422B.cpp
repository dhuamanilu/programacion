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
        FOR(j,0,m){
            cin>>a[i][j];
        }
    }
    //a[0][0] a[0][m-1] a[n-1][0] a[n-1][m-1]
    ll ans=0;
    FOR(i,0,n){
        FOR(j,0,m){
            vector <ll> temp;
            temp.push_back(a[i][j]);
            temp.push_back(a[i][m-j-1]);
            temp.push_back(a[n-i-1][j]);
            temp.push_back(a[n-i-1][m-j-1]);
            sort(all(temp));
            ll prom=(temp[1]+temp[2])/2;
            ll add=0;
            FOR(k,0,4){
                add+=abs(temp[k]-prom);
            }
            ans+=add;
        }
    }
    cout<<ans/4<<"\n";
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








