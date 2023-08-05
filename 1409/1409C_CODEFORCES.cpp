#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FOR1(i, a, b) for (int i=a; i<=(b); i++)
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
    ll pri=0,raz=0,act=LONG_LONG_MAX,last=LONG_LONG_MAX;
    FOR1(r,1,n){
        if((y-x)%r==0){
            FOR1(i,1,n){
                if((x-i)%r==0){
                    ll pos=(y-i)/r;

                    if(pos< act && i+r*(n-1) < last){
                        act=pos;
                        last=i+r*(n-1);
                        pri=i;
                        raz=r;
                    }
                }
            }
        }
    }
    ll var=pri;
    FOR1(i,0,act){
        cout<<var<<" ";
        var+=raz;
    }
    cout<<"\n";

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








