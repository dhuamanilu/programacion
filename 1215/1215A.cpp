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
    ll a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    ll mini=0,maxi;
    if((k1-1)*a1+(k2-1)*a2 >=n){
        mini=0;
    }
    else{
        n-=(k1-1)*a1+(k2-1)*a2;
        ll auxi1=a1,auxi2=a2,auxn=n;
        while(auxn>0 && (auxi1>0 || auxi2>0) ){
            auxn--;
            mini++;
            auxi1--;
            auxi2--;
        }
    }

    cout<<mini<<" "<<maxi<<"\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*if (fopen("abcd.in", "r")) {
		freopen("billboard.in", "r", stdin);
		freopen("billboard.out", "w", stdout);
    }*/
  	int t=1;
    //cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}








