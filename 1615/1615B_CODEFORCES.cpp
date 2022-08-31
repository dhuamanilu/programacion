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

const int maxl=20;
const int maxn=200005;
int s[maxl][maxn];
void solve(){
    int l,r;
    cin>>l>>r;
    int ans=r-l+1;
    FOR(i,0,maxl){
        ans=min(ans,r-l+1-(s[i][r]-s[i][l-1]));
    }
    cout<<ans<<"\n";
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
    FOR(i,0,maxl){
        FOR(j,1,maxn){
            s[i][j]=s[i][j-1]+((j>>i)&1);
        }
    }
  	while(t--){
        solve();
  	}
	return 0;
}








