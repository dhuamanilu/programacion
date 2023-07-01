#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
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
    ll n;
    cin>>n;
    ll a[n];

    FOR(i,0,n){
        cin>>a[i];

    }
    vector<pair<ll,ll>> ans;
    sort(a,a+n);
    ll i=n-2,j=n-1;
    while(i>=0 && j>=0){
        if(a[j]>0 && a[i]>0){
            a[j]--;
            a[i]--;
            ans.pb({i+1,j+1});
        }
        else if(a[i]==0){
            i--;
        }
        else if(a[j]==0){
            j--;
        }
    }
    cout<<ans.size()<<"\n";
    for(auto & e : ans){
        cout<<e.f<<" "<<e.se<<"\n";
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








