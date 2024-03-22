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
    ll n,x,y;
    cin>>n>>x>>y;
    string a;
    cin>>a;
    string b;
    cin>>b;
    vll inds;
    FOR(i,0,n){
    	if(a[i]!=b[i]) inds.pb(i);
    }
    ll cont=inds.size();
    if(cont%2==1){
    	cout<<"-1\n";
    }
    else{
    	if(cont==2){
    		if(inds[0]+1==inds[1]){
    			cout<<min(y*(cont),
    			x)<<"\n";
    		}
    		else{
    			cout<<y*(cont/2)<<"\n";
    		}
    	}
    	else{
    		cout<<y*(cont/2)<<"\n";
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








