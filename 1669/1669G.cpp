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
    char a[n+3][m+3];
    FOR(i,0,n){
        string s;
        cin>>s;
        FOR(j,0,m){
            a[i][j]=s[j];
        }
    }
    FOR(j,0,m){
        ll last=n-1;
        for(ll i=n-1;i>=0;i--){
            if(a[i][j]=='o'){
                last=i-1;
            }
            else{
                if(a[i][j]=='*'){
                    swap(a[i][j],a[last--][j]);
                }
            }
        }
    }
    FOR(i,0,n){
        FOR(j,0,m){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
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








