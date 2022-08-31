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
    ll n,m;
    cin>>n>>m;
    ll a[m];
    FOR(i,0,m){
        cin>>a[i];
        a[i]--;
    }
    sort(a,a+m);
    vector <ll> b;
    FOR(i,0,m){
        ll diff=a[(i+1)%m]-a[i];
        //cout<<a[(i+1)%m]<<" "<<a[i]<<"\n";
        if(diff<=0) diff+=n;
        b.emplace_back(diff-1);
    }
    sort(b.rbegin(),b.rend());
    /*for(auto e : b){
        cout<<e<<" ";
    }*/

    ll safe=0;
    FOR(i,0,m){
        ll auxi =b[i]-4*i;
        if(auxi>=1)
            safe+=max(1ll,auxi-1);
    }
    cout<<n-safe<<"\n";
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








