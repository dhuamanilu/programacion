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
ll dp[20][2][11];
ll seen[20][2][11];
vl digits;
ll tam;

void clear(){
    for(ll i=0;i<20;i++){
        for(ll j=0;j<2;j++){
            for(ll it=0;it<11;it++){
                dp[i][j][it]=0;
                seen[i][j][it]=0;
            }
        }
    }
}
ll f(ll pos,ll tight,ll lastdigit){
    if(pos==tam){
        return 1;
    }
    if(seen[pos][tight][lastdigit]){
        return dp[pos][tight][lastdigit];
    }
    ll limA=tight ? digits[pos] : 9;
    ll cant=0;
    for(ll i=0;i<=limA;i++){
        if(lastdigit!=10 && i==lastdigit) continue;
        ll newtight=1;
        if(tight==0){
            newtight=0;
        }
        else{
            if(i < digits[pos]){
                newtight=0;
            }
        }
        ll newlastdigit=(lastdigit==10 & i==0) ? 10 : i;
        cant+=f(pos+1,newtight,newlastdigit);
    }
    //assert(lastdigit>=0);
    dp[pos][tight][lastdigit]=cant;
    seen[pos][tight][lastdigit]=1;
    return cant;
}
void solve(){
    ll a,b;
    cin>>a>>b;
    auto init_digits=[&](ll num){
        digits.clear();
        for(auto & e : to_string(num)){
            digits.emplace_back(e-'0');
        }
        tam=digits.size();
    };
    auto get_ans=[&](ll num){
        clear();
        init_digits(num);
        return f(0,1,10);
    };
    ll ans1=get_ans(b);
    ll ans2=get_ans(a-1);
    //dbg(ans1);
    //dbg(ans2);
    cout<<ans1-ans2<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    for(ll i=0;i<t;i++) {
        solve();
    }
}