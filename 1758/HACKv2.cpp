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
typedef vector <pair<ll,ll>> vpll;
vpll factorize(ll x){
    vpll ans;
    ll x2=x;
    for(ll i=2;i*i<=x;i++){
        if(x2%i==0){
            ll cont=0;
            while(x2%i==0){
                cont++;
                x2/=i;
            }
            if(cont>0){
                ans.pb({i,cont});
            }
        }
    }
    if(x2>1){
        ans.pb({x2,1});
    }
    return ans;
}
void solve(){
    ll x;
    cin>>x;
    auto vec=factorize(x);
    for(auto & e: vec){
        cout<<e.f<<" "<<e.se<<"\n";
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("hola.in", "r")) {
		freopen("hola.in", "r", stdin);
		freopen("ansmio.in", "w", stdout);
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








