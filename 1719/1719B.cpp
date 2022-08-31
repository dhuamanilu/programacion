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
    ll n,k;
    cin>>n>>k;
    vector <pair<ll,ll>> a;
    for(int i=1;i<=n;i+=2){
        ll auxi1=i,auxi2=i+1;
        if( (((auxi1)+k)*(auxi2))%4==0){
            a.emplace_back(auxi1,auxi2);
        }
        else if((((auxi2)+k)*(auxi1))%4==0){
            a.emplace_back(auxi2,auxi1);
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    FOR(i,0,a.size()){
        cout<<a[i].first<<" "<<a[i].second<<"\n";
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








