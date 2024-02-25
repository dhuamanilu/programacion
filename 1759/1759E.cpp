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
void solve(){
    ll n,h;
    cin>>n>>h;
    vll a(n);
    FOR(i,0,n){
        cin>>a[i];
    }
    sort(all(a));
    ll ans=0;
    vector<vll> orders={{3,2,2},{2,3,2},
    {2,2,3}};
    for(auto & order : orders){
    	ll id=0,nh=h,res=0;
    	for(ll j=0;j<n;){
    		if(a[j]<nh){
    			res++;
    			nh+=a[j]/2;
    			j++;
    			continue;
    		}
    		if(id==3) break;
    		nh*=order[id++];
    	}
    	ans=max(ans,res);
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








