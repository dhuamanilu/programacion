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
ll dp[11][2][100][100];
ll seen[11][2][100][100];
vl digits;
ll tam;
ll k;
void clear(){
    for(ll i=0;i<11;i++){
        for(ll j=0;j<2;j++){
            for(ll it=0;it<100;it++){
                for(ll it2=0;it2<100;it2++){
                    dp[i][j][it][it2]=0;
                    seen[i][j][it][it2]=0;
                }
            }
        }
    }
}
ll f(ll pos,ll tight,ll restomodk,ll restodsumigitos){
    assert(restomodk >=0 && restomodk<k);
    assert(restodsumigitos >=0 && restodsumigitos<k);
    if(pos==tam){
        if(restomodk==0 && restodsumigitos==0) return 1;
        else return 0;
    }
    if(seen[pos][tight][restomodk][restodsumigitos]){
        return dp[pos][tight][restomodk][restodsumigitos];
    }
    ll limA=tight ? digits[pos] : 9;
    ll cant=0;
    for(ll i=0;i<=limA;i++){
        ll newtight=1;
        if(tight==0){
            newtight=0;
        }
        else{
            if(i < digits[pos]){
                newtight=0;
            }
        }
        ll newrestomodk=(10*restomodk+i)%k;
        ll newrestosumdigits=(restodsumigitos + i)%k;
        cant+=f(pos+1,newtight,newrestomodk,newrestosumdigits);
    }
    dp[pos][tight][restomodk][restodsumigitos]=cant;
    seen[pos][tight][restomodk][restodsumigitos]=1;
    return cant;
}
void solve(ll tc,ll a,ll b){
    
    if(k>100){
        cout<<"Case "<<tc+1<<": "<<"0\n";
    }
    else{
        for(auto &e : to_string(b)){
            digits.emplace_back(e-'0');
        }
        tam=digits.size();
        //dbg("hola");
        ll ans1=f(0,1,0,0);
        //dbg(ans1);
        digits.clear();
        for(auto &e : to_string(a-1)){
            digits.emplace_back(e-'0');
        }
        tam=digits.size();
        clear();
        ll ans2=f(0,1,0,0);
        //dbg(ans2);
        cout<<"Case "<<tc+1<<": "<<ans1-ans2<<"\n";
        clear();
    }
}
mt19937 rng(0); // or mt19937_64
//? /Custom Helpers
//? Generator
int rng_int(int L, int R) { assert(L <= R);
	return uniform_int_distribution<int>(L,R)(rng);  }
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }
//? /Generator
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    clear();
    while(1){
        ll a=rng_ll(1ll,10000000ll);
        ll b=rng_ll(a,a+10000000ll);
        k=50;
        solve(100,a,b);
    }
    ll t=1;
    cin>>t;
    for(ll i=0;i<t;i++) {
        ll a,b;
        cin>>a>>b>>k;
        solve(i,a,b);
    }
}