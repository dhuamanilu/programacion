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
ll powb(ll a, ll b) {
    if (b==0) return 1;
    ll res = powb(a, b/2);
    if (b%2)
        return res*res*a;
    else
        return res*res;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll ans=LONG_LONG_MIN;
    FOR(i,0,(1<<n)){
        if(__builtin_popcount(i)!=n-k) continue;
        vll v;
        FOR(j,0,n){
            if(i&(1<<j)){
                v.pb(a[j]);
            }
        }
        /*for(auto e : v){
            cout<<e<<" ";
        }
        cout<<"\n";*/
        ll sum=0,cont=0;
        while(!v.empty()){
            ll d=v.back();
            //cout<<"pow 10 0 : "<<pow(10,0)<<"\n";
            sum+=(ll) powb(10,cont)*d;
            cont++;
            v.pop_back();
        }
        if(sum>ans){
            ans=sum;
            //cout<<"este es el num" <<sum<<"\n";
        }

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








