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
const int MX = 1000005;
const int N=1000+3;
bool prime[MX];
void solve(){
    ll n,e;
    cin>>n>>e;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll ans=0;
    vector <ll> l(n,0),r(n,0);
    FOR(i,0,e){
        ll aux=i,cnt=0;
        while(aux<n){
            if(a[aux]>1){
                l[aux]=cnt+1;
                cnt=0;
            }
            else{
                cnt++;
            }
            aux+=e;
        }
        cnt=0;
        aux-=e;
        while(aux>=0){
            if(a[aux]>1){
                r[aux]=cnt+1;
                cnt=0;
            }
            else{
                cnt++;
            }
            aux-=e;
        }
    }
    FOR(i,0,n){
        if(prime[a[i]]){
            ans+=l[i]*r[i]-1;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(prime, 1, sizeof(prime));
    prime[0]=prime[1]=false;
    for (ll p=2;p*p<=MX;p++) {
        if(prime[p]){
            for(ll i=p*p;i<=MX;i+=p)
                prime[i]=false;
        }
    }
    //cout<<"SFAFAAS2";
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}








