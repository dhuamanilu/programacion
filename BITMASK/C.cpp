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
//#define all(x) bg(x), end(x)

#define dbg(x) cout << "Line(" << __LINE__ << "): " << "\033[1;34m" << #x << "\033[0;32m = \033[35m" << to_string(x) << "\033[0m" << endl;
#define GA dbg(0)
#define RAYA   dbg("================================");

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void solve(){
    
    bitset<64> num(0);
    ll q;
    cin>>q;
    while(q--){
        ll type;
        cin>>type;
        if(type>=0 && type<=3){
            ll pos;
            cin>>pos;
            if(type==0){
                cout<<num[pos]<<"\n";
            }
            else if(type==1){
                num.set(pos);
            }
            else if(type==2){
                num.reset(pos);
            }
            else{
                num.flip(pos);
            }
        }
        else{
            if(type==4){
                cout<<ll(num.all())<<"\n";
            }
            else if(type==5){
                cout<<ll(num.any())<<"\n";
            }
            else if(type==6){
                cout<<ll(!num.any())<<"\n";
            }
            else if(type==7){
                cout<<num.count()<<"\n";
            }
            else{
                cout<<num.to_ullong()<<"\n";
            }
        }
    }

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}