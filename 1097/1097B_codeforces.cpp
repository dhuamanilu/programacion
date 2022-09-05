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



struct Rect {
	ll x1, y1, x2, y2;
	ll area() {
		return (y2 - y1) * (x2 - x1);
	}
};

ll intersect(Rect p, Rect q) {
	ll xOverlap = max(0LL, min(p.x2, q.x2) - max(p.x1, q.x1));
	ll yOverlap = max(0LL, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}
ll intersectThree(Rect a, Rect b, Rect c) {
	ll xOverlap = max(min(min(a.x2, b.x2), c.x2) - max(max(a.x1, b.x1), c.x1), (ll)0);
	ll yOverlap = max(min(min(a.y2, b.y2), c.y2) - max(max(a.y1, b.y1), c.y1), (ll)0);
	return xOverlap * yOverlap;
}
bool covered(ll a,ll b,ll c,ll d,ll e,ll f){
    return a>= c && a<=e && b>=d && b<=f ;
}
void solve(){
	ll w,h;
	cin>>w>>h;
	Rect a;
	cin>>a.x1>>a.y1>>a.x2>>a.y2;
	ll m,n;
	cin>>m>>n;
	FOR(i,0,w){
        FOR()
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