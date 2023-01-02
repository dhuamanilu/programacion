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
    ll n,m;
    cin>>n>>m;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll b[m];
    FOR(i,0,m){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    FOR(i,0,m){
        bool ok=false;
        FOR(j,0,n){
            if(b[i]>a[j]){
                a[j]=b[i];
                ok=true;
                break;
            }

        }
        if(!ok){
            a[0]=b[i];
        }
        sort(a,a+n);
    }
    ll ans=0;
    FOR(i,0,n){
        ans+=a[i];
    }
    cout<<ans<<"\n";
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






