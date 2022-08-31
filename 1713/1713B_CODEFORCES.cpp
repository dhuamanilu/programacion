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
    ll maxi[n];
    ll mini[n];
    maxi[0]=a[0];
    FOR(i,1,n){
        maxi[i]=max(maxi[i-1],a[i]);
    }
    mini[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        mini[i]=max(mini[i+1],a[i]);
    }

    FOR(i,1,n-1){
        if(a[i]<maxi[i-1] && a[i]<mini[i+1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

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








