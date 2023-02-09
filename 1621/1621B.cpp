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
    ll n;
    cin>>n;
    ll a[n];
    ll maxi=0,costLen=0,l,r,c,miniL=LONG_LONG_MAX,maxiR=LONG_LONG_MIN,costL=LONG_LONG_MAX,costR=LONG_LONG_MAX;
    FOR(i,0,n){
        cin>>l>>r>>c;

        if(l<miniL){
            miniL=l;
            costL=LONG_LONG_MAX;
        }
        if(l==miniL){
            costL=min(costL,c);
        }
        if(r>maxiR){
            maxiR=r;
            costR=LONG_LONG_MAX;
        }
        if(r==maxiR){
            costR=c;
            costR=min(costR,c);
        }
        if(maxi<r-l+1){
            maxi=r-l+1;
            costLen=LONG_LONG_MAX;
        }
        if(maxi==r-l+1){
            costLen=min(costLen,c);
        }
        ll cost=costR+costL;
        if(maxi==maxiR-miniL+1){
            cost=min(cost,costLen);
        }
        cout<<cost<<"\n";
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








