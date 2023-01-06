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
    ll a[n][m];
    FOR(i,0,n){
        string s;
        cin>>s;
        FOR(j,0,m){
            char aux=s[j];
            if(aux=='*'){
                a[i][j]=1;
            }
            else{
                a[i][j]=0;
            }
        }
    }

    vector <vll> width(n,vll(m,1e18));
    FOR(i,0,n){
        ll cont=0;
        FOR(j,0,m){
            if(a[i][j])
                cont+=a[i][j];
            else cont=0;
            width[i][j]=min(width[i][j],cont);
        }
        cont=0;
        for(ll k=m-1;k>=0;k--){
            if(a[i][k])
                cont+=a[i][k];
            else cont=0;
            width[i][k]=min(width[i][k],cont);
        }
    }
    ll ans=0;
    FOR(i,0,n){
        FOR(j,0,m){
            FOR(k,i,n){
                if(width[k][j]<=k-i) break;
                ans++;
            }
        }
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








