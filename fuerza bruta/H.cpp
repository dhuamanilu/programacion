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
    ll n;
    cin>>n;
	vl a(n);
	for(auto&e:a)cin>>e;
    ll idx=0;
	for(int i=0;i<n;i++){
		if(a[i]!=1 && a[i]!=-1){
			idx=i;
			break;
		}
	}
	const ll BIG=(ll)1e18;
	ll L1=BIG,R1=-BIG,L2=BIG,R2=-BIG,sum=0;
	for(ll i=idx-1;i>=0;i--){
		sum+=a[i];
		L1=min(L1,sum);
		R1=max(R1,sum);
	}
	sum=0;
	for(ll i=idx+1;i<n;i++){
		sum+=a[i];
		L2=min(L2,sum);
		R2=max(R2,sum);
	}
	set<ll> values;
	vl a1,a2;
	for(int i=0;i<idx;i++){
		a1.emplace_back(a[i]);
	}
	for(int i=idx+1;i<n;i++)
		a2.emplace_back(a[i]);
	}
	auto get=[](vl &arr)->ll{
		if(arr.empty()) return 0;
		ll res = arr[0];
		ll maxEnding = arr[0];
		for (ll i = 1; i < arr.size(); i++) {
			maxEnding = max(maxEnding + arr[i], arr[i]);
			res = max(res, maxEnding);
		}
		return max(0ll,res);
	};
	auto maxiL=get(a1);
	auto maxiR=get(a2);
	for(auto &e:a1) e*=-1;
	auto miniL=-1*get(a1);
	for(auto &e:a2) e*=-1;
	auto miniR=-1*get(a2);
	for (ll i = miniL; i <= maxiL; i++) {
		values.insert(i);
	}
	for (ll i = miniR; i <= maxiR; i++) {
		values.insert(i);
	}
	values.insert(0);
	values.insert(a[idx]);	
	for (ll i = L2; i <= R2; i++) {
		values.insert(i);
	}
	ll Lfinal=min({L1,L2,L1+L2}),Rfinal=max({R1,R2,R1+R2});
	for (ll i = Lfinal; i <= Rfinal; i++){
		values.insert(a[idx] + i);
	}
	cout<<values.size()<<"\n";
	for(auto &x:values){
		cout<<e<<" ";
	}
	
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) solve();
}