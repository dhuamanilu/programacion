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
ll dp[61][2][2][2][2][2];
ll seen[61][2][2][2][2][2];
vl digitsL,digitsR;
ll tam;
ll f(ll pos,ll tightA_L,ll tightA_H,ll tightB_L,ll tightB_H,ll AB){
    if(pos==tam){
        return 0;
    }
    if(seen[pos][tightA_L][tightA_H][tightB_L][tightB_H][AB]){
        return dp[pos][tightA_L][tightA_H][tightB_L][tightB_H][AB];
    }
    ll best=0;
    ll low_A=tightA_L ? digitsL[pos] : 0;
    ll high_A=tightA_H ? digitsR[pos] : 1;
    ll low_B=tightB_L ? digitsL[pos] : 0;
    ll high_B=tightB_H ? digitsR[pos] : 1;
    for(ll i=low_A;i<=high_A;i++){
        for(ll j=low_B;j<=high_B;j++){
            if(i > j && !AB){
                continue;
            }
            
            ll new_tightA_L=1;
            if(tightA_L==0){
                new_tightA_L=0;
            }
            else{
                if(i > digitsL[pos]){
                    new_tightA_L=0;
                }
            }
            ll new_tightA_H=1;
            if(tightA_H==0){
                new_tightA_H=0;
            }
            else{
                if(i < digitsR[pos]){
                    new_tightA_H=0;
                }
            }
            //-------------- 
            ll new_tightB_L=1;
            if(tightB_L==0){
                new_tightB_L=0;
            }
            else{
                if(j > digitsL[pos]){
                    new_tightB_L=0;
                }
            }
            ll new_tightB_H=1;
            if(tightB_H==0){
                new_tightB_H=0;
            }
            else{
                if(j < digitsR[pos]){
                    new_tightB_H=0;
                }
            }
            ll contr=(i^j)*(1ll<<(tam-1-pos));
            ll newAB=0;
            if(AB){
                newAB=1;
            }
            else{
                if(i < j){
                    newAB=1;
                }
            }
            ll sub=f(pos+1,new_tightA_L,new_tightA_H,new_tightB_L,new_tightB_H,newAB);
            best=max(best,contr+sub);
        }
    }
    dp[pos][tightA_L][tightA_H][tightB_L][tightB_H][AB]=best;
    seen[pos][tightA_L][tightA_H][tightB_L][tightB_H][AB]=1;
    return best;
}
void solve(){
    ll l,r;
    cin>>l>>r;
    bitset<61> val1(l),val2(r);
    for(ll i=60;i>=0;i--){
        digitsL.emplace_back(val1[i]);
    }
    for(ll i=60;i>=0;i--){
        digitsR.emplace_back(val2[i]);
    }
    tam=digitsL.size();
    ll ans=f(0,1,1,1,1,0);
    cout<<ans<<"\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}