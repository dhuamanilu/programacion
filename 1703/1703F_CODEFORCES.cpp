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
    ll a[n+1];
    FOR(i,0,n){
        cin>>a[i+1];
    }
    ll r=0;
    vll v;
    for(int i=1;i<=n;i++){
        if(a[i]>=i) continue;
        ll auxi=1LL*(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
        //cout<<"i actual y vector v:"<<i<<"\n";
        //cout<<"auxi : "<<auxi<<"\n";
        r+=auxi;
        v.push_back(i);
    }
    cout<<r<<"\n";

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








