#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
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
const int MX = 200005;
const int N=1000+3;
const int INF=100000000;

bool isSquare(ll x){
    if (x>=0) {
        ll sr=sqrt(x);
        return(sr*sr==x);
    }
    return false;
}


void solve(){
    ll n;
    cin>>n;
    for(ll i=2;i*i*i<=n;i++){
        if(n%i==0){
            if(isSquare(n/i)){
                ll p,q;
                p=(ll)sqrt(n/i);
                q=i;
                cout<<p<<" "<<q<<"\n";
                return;
            }
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
