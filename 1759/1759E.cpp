#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)
#define FOR1(i, a, b) for (long long i=a; i<=(b); i++)
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
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve(){
    ll n,h;
    cin>>n>>h;
    vll a(n);
    FOR(i,0,n){
        cin>>a[i];
    }
    sort(all(a));
    ll green=2,blue=1,ans=0;
    FOR(i,0,n){
    	if(h>a[i]){
    		h+=a[i]/2;
    		ans++;
    		continue;
    	}
    	ll ind=-1;
    	pair<ll,ll> response={0,0};
        FOR1(k,0,1){
        	FOR1(j,0,2){
        		if(green>=j && blue>= k){
        			ll newH=h*binpow(2,j)*binpow(3,k);
        			ll newInd=lower_bound(all(a),newH)-a.begin();
        			if(newInd>ind){
        				ind=newInd;
        				response=mp(j,k);
        			}
        			else if(newInd==ind){
        				response=min(response,mp(j,k));
        			}
        		}
        	}
        }
        h*=binpow(2,response.f)*binpow(3,response.se);
        green-=response.f;
        blue-=response.se;
        
        if(h>a[i]){
    		h+=a[i]/2;
    		ans++;
    	}
    }
    cout<<ans<<"\n";
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








