#include <bits/stdc++.h>
using namespace std;

//* Debugger
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A>
string to_string(A v);

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "[";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "]";
    return res;
}
//* /Debugger

using ll = long long;
using pl = pair<ll, ll>;

#define tcT template<class T
tcT> using V = vector<T>;
using vl = V<ll>;

#define sz(x) int((x).size())
#define all(x) bg(x), end(x)

#define dbg(x) cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << #x << "\033[0;32m = \033[35m" << to_string(x) << "\033[0m" << endl;
#define GA dbg(0)
#define RAYA   dbg("================================");

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void solve(){
    ll l,r,g;
    cin>>l>>r>>g;
    pl ans={-1,-1};
	ll L1=l/g,R1=(r+g-1)/g;
	if(L1==R1){
		if(L1==1){
			ans=make_pair(L1*g,R1*g);
		}
		else ans=make_pair(-1,-1);
	} 
	for(ll i=L1;i<=R1;i++){
	    if(__gcd(i,R1)==1){
	        ll distAns=(ans.second-ans.first);
	        ll distAct=g*(R1-i);
	        if(distAct > distAns){
	            ans=make_pair(g*(i),g*(R1));
	        }
	        break;
	    }
	    else{
	        for(ll j=R1;j>=i;j--){
	            if(__gcd(i,j)==1){
	                ll distAns=(ans.second-ans.first);
        	        ll distAct=g*(j-i);
        	        if(distAct > distAns){
        	            ans=make_pair(g*(i),g*(j));
        	        }
        	        break;
	            }
	        }
	    }
	}
	cout<<ans.first<<" "<<ans.second<<"\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) solve();
}