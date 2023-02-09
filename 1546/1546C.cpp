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
const int MX = 100005;
const int N=1000+3;

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    vector<vector<ll>> b(MX,vector<ll>(2,0));
    FOR(i,0,n){
        cin>>a[i];
        if(i&1){
            b[a[i]][1]++;
        }
        else{
            b[a[i]][0]++;
        }
    }
    sort(a,a+n);
    FOR(i,0,n){
        if(i&1){
            b[a[i]][1]--;
        }
        else{
            b[a[i]][0]--;
        }
    }
    FOR(i,0,n){
        if(b[a[i]][0] !=0 || b[a[i]][1]!=0){
            cout<<"NO\n";
            return;
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








