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
    ll n;
    cin>>n;
    ll a[n],sum=0;
    FOR(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }
    for(ll i=n;i>=1;i--){
        if(sum%i==0){
            ll add=0,obj=sum/i;
            bool ok=true;
            FOR(j,0,n){
                add+=a[j];
                if(add>obj){
                    ok=false;
                    break;
                }
                else if(add==obj){
                    add=0;
                }
            }
            if(ok){
                cout<<n-i<<"\n";
                return;
            }
        }
    }

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
