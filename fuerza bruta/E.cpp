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
    string s;
    cin>>s;
    set<ll> ids;
    ll n=s.size();
    for(int i=0;i+3<n;i++){
        if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){
            ids.insert(i);
        }
    }
    ll q;
    cin>>q;
    string ver="1100";
    while(q--){
        //dbg(s);
        ll i,v;
        cin>>i>>v;
        i--;
        if((s[i]-'0')!=v){
            for(int k=0;k<4;k++){
                if(ids.count(i-k)){
                    ids.erase(i-k);
                    break;
                }
            }
            s[i]='0'+v;
            for(int k=0;k<4;k++){
                bool ok=true;
                if(i<k){
                    continue;
                }
                for(int xd=0;xd<4;xd++){
                    if(s[i-k+xd]!=ver[xd]){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    ids.insert(i-k);
                }
            }
        }
        cout<<(ids.size() > 0 ? "YES\n":"NO\n");
    }

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) solve();
}