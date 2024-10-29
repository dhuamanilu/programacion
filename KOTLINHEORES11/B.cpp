#include <bits/stdc++.h>
using namespace std;


// building blocks
using ll  = long long;
using db  = long double; // or double, if TL is tight
using str = string;      // yay python!

#define tcT template <class T
#define tcTU tcT, class U
//! ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vl = V<ll>;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

vl solve(ll n) {
	vl a;
	if(n%2==0){
		a.push_back(1);
		a.push_back(2);
		if(n>=2){
			for(ll i=n;i>=3;i--){
				a.push_back(i);
			}
		}
	}
	else{
		a.push_back(1);
		a.push_back(n);
		a.push_back(2);
		if(n>=3){
			for(ll i=n-1;i>=3;i--){
				a.push_back(i);
			}
		}
	}

	return a;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;

    for(int idx = 0; idx < t; idx++) {
		ll n;
		cin>>n;
		auto x=solve(n);
        each(e,x)cout<<e<<" ";
		cout<<"\n";
    }
}








