#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
    ll n;
    cin>>n;
    ll a[n];
    mll m;
    FOR(i,0,n){
        cin>>a[i];
        m[a[i]]++;
    }
    for(auto e : m){
        if(e.se>1){
            cout<<"NO\n";
            return;
        }
    }
    ll lu=2600;
    FOR(x,0,lu){
        bool ok=true;
        FOR(i,0,n){
            FOR(j,i+1,n){
                if(__gcd(a[i]+x,a[j]+x)!=1){
                    ok=false;
                    break;
                }
            }
            if(!ok){
                break;
            }
        }
        if(!ok){
            continue;
        }
        else{
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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








