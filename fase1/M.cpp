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
struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    vl xd(n);
    for(auto &e : xd)cin>>e;
    ll k;
    cin>>k;
    vl pref(n,0);
    //pref[0]=xd[0];
    const ll BIG=(ll)1e15;
    ll maxi=-BIG,idx=1;
    for(ll i=0;i<n;i++){
        if(i>0){
            pref[i]=pref[i-1]+xd[i];
        }
        else{
            pref[i]=xd[i];
        }
        if((i+1)!=k){
            if(pref[i] > maxi){
                maxi=pref[i];
                idx=i+1;
            }
        }
    }
    if((maxi + a) >= (b + pref[k-1])){
        cout<<"SIM\n";
        cout<<idx<<"\n";
    }
    else{
        cout<<"NAO\n";
    }


}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}