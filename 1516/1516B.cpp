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
    ll xo=0;
    FOR(i,0,n){
        cin>>a[i];
        xo^=a[i];
    }
    if(n==2){
        if(a[0]==a[1]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return;
    }
    if(xo==0){
        cout<<"YES\n";
    }
    else{
        ll xo2=0,cont=0;
        FOR(i,0,n){
            xo2^=a[i];
            if(xo2==xo){
                xo2=0;
                cont++;
            }
        }
        if(cont>=3){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }


    }
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








