#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
typedef vector<ll> vll;
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
    ll n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    int cont1=0,cont2=0,cont3=0,cont4=0;
    FOR(i,0,n){
        if(a[i]=='0') cont1++;
        else cont2++;
    }
    FOR(i,0,m){
        if(b[i]=='0') cont3++;
        else cont4++;
    }
    if(cont4>cont2 || cont3>cont1){
        cout<<"NO\n";
        return;
    }



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








