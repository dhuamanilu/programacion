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
    FOR(i,0,n){
        cin>>a[i];
    }
    ll b[n];
    FOR(i,0,n){
        cin>>b[i];
    }
    vector <ll> diff(n,0);
    FOR(i,0,n){
        diff[i]=a[i]-b[i];
    }
    sort(all(diff));
    ll ans=0;
    FOR(i,0,n){
        ll difer=diff[i];
        if(difer<=0) continue;
        //auto x=lower_bound(all(diff),-1ll*difer+1)-diff.begin();
        ll s=0,e=n-1,m=s+(e-s)/2,mejor=0;
        while(s<=e){
            m=s+(e-s)/2;
            if(difer+diff[m]>0){
                mejor=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        ans+=i-mejor;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








