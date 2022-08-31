#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)

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
const int MX = 100005;
const int N=1000+3;
ll res[MX];
void solve(){
    ll n;
    cin>>n;
    ll guarda=n;
    FOR(i,0,n){
        res[i]=0;
    }
    n--;
    while(n>0){
        ll i=0;
        for(i=0;i*i<n;i++);
        ll actual=n;
        for(ll j=i*i-n;j<=actual;j++){
            res[j]=n;
            n--;
        }
    }
    FOR(i,0,guarda){
        cout<<res[i]<<" ";
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









