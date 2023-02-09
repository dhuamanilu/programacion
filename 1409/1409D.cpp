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
ll suma(ll a){
    ll sum=0;
    while(a){
        ll d=a%10;
        sum+=d;
        a/=10;
    }
    return sum;
}
void solve(){
    ll n,s;
    cin>>n>>s;
    if(suma(n)<=s){
        cout<<"0\n";
    }
    else{
        ll guarda=1,ans=0;
        while(true){

            ll d=(n/guarda)%10;
            n+=((10-d)%10)*guarda;
            ans+=((10-d)%10)*guarda;
            if(suma(n)<=s) break;
            //cout<<n<<"\n";

            guarda*=10;
        }
        cout<<ans<<"\n";
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








