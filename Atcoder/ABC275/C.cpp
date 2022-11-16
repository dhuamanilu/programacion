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

void solve(){
    ll a[9][9];
    FOR(i,0,9){
        string s;
        cin>>s;
        FOR(j,0,9){
            a[i][j]=(s[j]=='#');
        }
    }

    ll cont=0;
    FOR(i,0,9){
        FOR(j,0,9){
            FOR(k,0,9){
                FOR(l,0,9){
                    ll dx=,dy=;
                }
            }
        }
    }
    cout<<cont/4<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  	int t=1;
    //cin>>t;
  	while(t--){
        solve();
  	}
	return 0;
}
