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
    ll n;
    cin>>n;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    int b[]={0,4,8,15,16,23,42};
    int cont[]={0x3f3f3f3f,0,0,0,0,0,0,0};
    FOR(i,0,n){
        FOR(j,1,7){
            if(a[i]==b[j] && cont[j-1]>0){
                cont[j]++;
                cont[j-1]--;
            }
        }
    }
    cout<<n-6*cont[6]<<"\n";


    /*int b[]={4,8,15,16,23,42};
    FOR(i,0,6){
        if(f[b[i]]%6==0){
            continue;
        }

    }*/


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








