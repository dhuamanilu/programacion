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
const int MX = 100001;
const int N=1000+3;

void solve(){
    int n;
    cin>>n;
    ll a[n];
    ll sum=0;
    FOR(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum !=0){
        cout<<"NO\n";
        return;
    }
    bool ok=true;
    sum=0;
    FOR(i,0,n){
        sum+=a[i];
        if(sum<0){
            ok=false;
        }
    }
    sum=0;
    bool zero=false;
    FOR(i,0,n){
        sum+=a[i];
        if(sum==0){
            zero=true;
        }
        else if(zero){
            ok=0;
        }
    }
    if(ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";

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
