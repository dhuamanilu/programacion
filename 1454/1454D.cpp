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
    ll n,guarda=0;
    cin>>n;
    if(n==2){
        cout<<"1\n2\n";
        return;
    }
    if(n==3){
        cout<<"1\n3\n";
        return;
    }
    ll n2=n;
    ll ans=LONG_LONG_MIN;
    for (ll i=2;i*i<=n;i++){
        bool div=false;
        ll cont=0;
        while(n%i==0 && n>1){
            div=true;
            cont++;
            n/=i;
        }
        if(div){
            if(cont>ans){
                ans=cont;
                guarda=i;
            }
            ans=max(ans,cont);
        }
        if(n==1) break;
    }
    //cout<<"este es el nas: "<<ans-1<<"\n";
    if(ans==LONG_LONG_MIN){
        cout<<"1\n"<<n2<<"\n";
        return;
    }
    cout<<ans<<"\n";
    FOR(i,0,ans-1){
        cout<<guarda<<" ";
    }
    cout<<n2/(ll)pow(guarda,ans-1)<<"\n";
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








