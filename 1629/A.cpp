#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<ll,ll> mll;
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
    vll unos(n,0),ceros(n,0);
    unos[0]=a[0];
    if(a[0]==0){
        ceros[0]=1;
    }
    FOR(i,1,n){
        unos[i]=unos[i-1]+a[i];
        if(a[i]==0){
            ceros[i]=ceros[i-1]+1;
        }
        else{
            ceros[i]=ceros[i-1];
        }
    }
    if(unos[n-1]==n ){
        cout<<"0\n";
        return;
    }
    ll ans=LONG_LONG_MAX;
    FOR(i,0,n){
        ans=min(ans,max(unos[i],ceros[n-1]-ceros[i]));
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
