#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
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
const int MAXN = 100010;
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> cont(2,0);
    ll par=0,impar=0;
    FOR(i,0,n){
        cin>>a[i];
        a[i]%=2;
        cont[a[i]]++;
        if(a[i]%2==0) par++;
        else impar++;
    }
    if(abs(par-impar)>1){
        cout<<"-1\n";
        return;
    }
    ll ans=1e18;
    FOR(k,0,2){
        if(cont[k]!=(n+1)/2){continue;}

        ll cont=0;
        vll mo(2,0);
        FOR(i,0,n){
            mo[a[i]]++;
            if(a[i]==k){
                cont+=abs(mo[k]-mo[k^1]-1);
            }
        }
        ans=min(ans,cont);
    }
    if(ans==1e18) ans=-1;
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








