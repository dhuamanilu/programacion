#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
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
const int MX = 200005;
const int N=1000+3;
const int INF=100000000;

void solve(){
    ll n;
    cin>>n;
    ll a[n+2];
    ll sold=0;
    vector <bool> visto(n+2,false);
    FOR(i,0,n){
        cin>>a[i];
        if(a[i]>=n+2){
            sold++;
        }
        else if(visto[a[i]]){
            sold++;
        }
        else{
            visto[a[i]]=true;
        }
    }
    ll l=1,r=n+1;
    while(true){
        while(visto[l]) l++;
        while(r!=0 && !visto[r]) r--;
        if(sold>=2){
            sold-=2;
            visto[l]=true;
        }
        else{
            if(l>=r) break;
            visto[r]=false;
            sold++;
        }
    }
    cout<<l-1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  	int t=1;
    //cin>>t;
  	while(t--){
        solve();
  	}
	return 0;
}
