#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)
#define lb lower_bound
#define ub upper_bound
#define se second
#define all(x) x.begin(), x.end()
#define ins insert
#define pb push_back
#define f first
#define mp make_pair
const int MX=200004;
const int MOD=1000000007;

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    vector <ll> m(1001,0);
    FOR(i,0,n){
        cin>>a[i];
        m[a[i]]++;
    }
    FOR(i,1,1001){
        if(m[i]>(n+1)/2){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}








