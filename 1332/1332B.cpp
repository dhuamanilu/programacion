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

ll findDivisor(ll n){
    for(ll i = 2;i*i<=n;i++){
        if (n%i==0){
            return i;
        }
    }
    return n;
}
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    vll primes(11,1ll);
    vll colors(n,-1);
    FOR(i,0,n){
        FOR(j,0,11){
            //cout<<primes[0]<<"\n";
            if(a[i]%primes[j]==0){
                colors[i]=j+1;
                if(primes[j]==1ll){
                    primes[j]=findDivisor(a[i]);
                }
                break;
            }
        }
    }
    cout<<*max_element(all(colors))<<"\n";
    for(auto e : colors){
        cout<<e<<" ";
    }
    cout<<"\n";
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








