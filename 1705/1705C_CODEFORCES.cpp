
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
    ll n,c,q;
    cin>>n>>c>>q;
    string s;
    cin>>s;
    vector <pair<ll,ll>> a(c+1);
    a[0].first=0;
    a[0].second=n;
    vector <ll> diff(c+1);
    for(int i=1;i<=c;i++){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        a[i].first=a[i-1].second;
        a[i].second=a[i].first+(r-l+1);
        diff[i]=a[i].first-l;
    }
    FOR(i,0,q){
        ll k;
        cin>>k;
        k--;
        for(int j=c;j>=1;j--){
            //cout<<"este es el k actual : "<<k<<"\n";
        	if(k<a[j].first) continue;
        	else{
                k-=diff[j];
        	}

        }

        cout<<s[k]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("abcd.in", "r")) {
		freopen("billboard.in", "r", stdin);
		freopen("billboard.out", "w", stdout);
    }
  	int t=1;
    cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}
