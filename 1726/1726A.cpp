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
    ll n;
    cin>>n;
    ll a[n];
    ll maxi=LONG_LONG_MIN,mini=LONG_LONG_MAX,indmax=0,indmin=0;
    FOR(i,0,n){
        cin>>a[i];
        if(a[i]>=maxi){
            maxi=a[i];
            indmax=i;
        }
        if(a[i]<=mini){
            mini=a[i];
            indmin=i;
        }
    }
    //cout<<indmin<<" "<<indmax<<"\n";
    if(a[0]==mini || a[n-1]==maxi || (indmin+n-1-indmax)%n==0){
        cout<<maxi-mini<<"\n";
        return;
    }
    ll res=0-LONG_LONG_MIN;
    FOR(i,0,n-1){
        res=max(res,a[i]-a[i+1]);
    }
    ll r1=maxi-a[0],r2=a[n-1]-mini;
    cout<<max(r1,max(res,r2))<<"\n";
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








