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
const int MX = 100001;
const int N=1000+3;
void solve(){
    ll n,m;
    cin>>n>>m;
    char a[n+1][m+1];
    bool nocero=true;
    ll cont1=0,cont0=0;
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>a[i][j];
            nocero&=(a[i][j]=='0');
            if(a[i][j]=='1') cont1++;
            else cont0++;
        }
    }
    if(nocero){
        cout<<"0\n";
        return;
    }
    ll sum=0,quita=LONG_LONG_MAX;
    FOR(i,0,n-1){
        FOR(j,0,m-1){
            sum=a[i][j]-'0'+a[i+1][j]-'0'+a[i][j+1]-'0'+a[i+1][j+1]-'0';
            if(sum==0) continue;
            quita=min(quita,max(1LL,sum-1));
        }
    }
    cout<<cont1-quita+1<<"\n";

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








