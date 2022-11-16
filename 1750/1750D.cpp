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
const int MOD =998244353;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;
vll getPrimes(ll e){
    vll aux;

    for(ll i=2;i*i<=e;i++){
        bool ok=false;
        while(e%i==0){
            e/=i;
            ok=true;

        }
        if(ok)
            aux.push_back(i);
    }
    if(e!=1) aux.push_back(e);
    return aux;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    ll a[n+1];
    FOR1(i,1,n){
        cin>>a[i];
    }
    FOR1(i,2,n){
        if(a[i-1]%a[i]){
            cout<<"0\n";
            return;
        }
    }
    vll primos=getPrimes(a[1]);
    map<pair<ll, ll>, ll> calculat;
    FOR(i,2,n+1){
        calculat[mp(a[i-1],a[i])]=0;
    }
    for(auto e : calculat){
        ll left=e.f.f/e.f.se;
        ll till=m/e.f.se;
        vll leftPrimes;
        for(auto fac : primos ){
            if(left%fac==0){
                leftPrimes.pb(fac);
            }
        }
        ll sz=leftPrimes.size();
        ll ans=0;
        for(ll mask=0;mask<(1<<sz);mask++){
            ll prod=1;
            ll cont=0;
            FOR(j,0,sz){
                if(mask&(1<<j)){
                    prod*=leftPrimes[j];
                    cont++;
                }
            }
            if(!(cont%2)){
                ans+=till/prod;
            }
            else{
                ans-=till/prod;
            }
            calculat[e.f]=ans;

        }

    }
    ll res=1;
    for(ll i=2;i<=n;i++){

        res*=(calculat[mp(a[i-1],a[i])] )%MOD;
        res%=MOD;
    }
    cout<<res<<"\n";

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








