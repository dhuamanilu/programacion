#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
//typedef vector<ll> vll;
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
const int MX = 100001;
const int N=1000+3;

void solve(){
    LL n,k;
    cin>>n>>k;
    if(k>=n){
        cout<<"1\n";
        return;
    }
    LL ans = n;
    for (LL j = 1; j * j <= n; j++) {
        if (n % j == 0) {
            if (j <= k) {
                ans = min(ans, n / j);
            }
            if (n / j <= k) {
                ans = min(ans, j);
            }
        }
    }
    cout << ans <<"\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*if (fopen("abcd.in", "r")) {
		freopen("billboard.in", "r", stdin);
		freopen("billboard.out", "w", stdout);
    }*/
  	int t=1;
    cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}
