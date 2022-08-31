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
    ll lim=1000000;
    FOR(i,0,lim){
        cout<<"a";
        if(i%10==0)cout<<" ";
    }
    cout<<"\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("prueba.txt", "r")) {
		//freopen("billboard.in", "r", stdin);
		freopen("prueba.txt", "w", stdout);
    }
  	int t=1;
    //cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}








