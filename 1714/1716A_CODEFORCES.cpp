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
    ll ans=0;
    if(n%3==0){
        cout<<n/3<<"\n";
        return;
    }
    else{
        if(n%3==1){
            if(n==1){
                cout<<"2\n";
                return;
            }
            ans+=2;
            n-=4;
            ans+=n/3;
            cout<<ans<<"\n";
            return;
        }
        else{
            ans++;
            n-=2;
            ans+=n/3;
            cout<<ans<<"\n";
            return;
        }
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








