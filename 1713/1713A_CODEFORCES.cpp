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
    ll n;
    cin>>n;
    ll xp=0;
    ll xm=0;
    ll yp=0;
    ll ym=0;

    FOR(i,0,n){
        ll x,y;
        cin>>x>>y;
        if(x==0){
            if(y>=0){
                yp=max(yp,y);
            }
            else{
                ym=min(ym,y);
            }
        }
        else{
            if(x>=0){
                xp=max(xp,x);
            }
            else{
                xm=min(xm,x);
            }
        }
    }


    ll res=abs(xp)+abs(xm)+abs(yp)+abs(ym);
    cout<<2*res<<"\n";

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








