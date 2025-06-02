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
void solve(ll tc){
    ll a,b;
    cin>>a>>b;
    ll val=0;
    for(int i=61;i>=0;i--){
        if((1ll<<i)&a){
            val+=(1ll<<i);
        }
        else{
            /*dbg(val|(1ll<<i));
            dbg(b);*/
            if((val|(1ll<<i))<=b){
                val|=(1ll<<i);
            }
        }
    }
    ll res=0;
    for(int i=61;i>=0;i--){
        if((1ll<<i)&a){
            ll comp=0;
            for(ll j=i-1;j>=0;j--){
                if(((1ll<<j)&a)==0){
                    comp+=(1ll<<j);
                }
            }
            if(comp+1<=(b-a)){
                /*for(ll k=61;k>=i+1;k--){
                    if((1ll<<k)&a)
                        res+=(1ll<<k);
                }*/
                break;
            }
            else res+=(1ll<<i);
        }
        else{
            
        }
    }
    cout<<"Case "<<tc+1<<": "<<val<<" "<<res<<"\n";

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    for(ll i=0;i<t;i++) solve(i);
}