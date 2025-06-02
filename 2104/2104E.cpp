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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<vector<int>> pos(k);
    for(int i=0;i<n;i++){
        pos[s[i]-'a'].push_back(i);
    }
    const ll BIG = (ll)1e18;
    vl dp(n,BIG);
    dp[n-1]=1ll;
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<k;j++){
            ll idx=upper_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin();
            if(idx==(ll)pos[j].size()){
                dp[i]=min(dp[i],1ll);
            }
            else{
                dp[i]=min(dp[i],1+dp[pos[j][idx]]);
            }
        }
    }
    //dbg(dp);
    ll q;
    cin>>q;
    while(q--){
        string t;
        cin>>t;
        ll act=-1,tam=t.size();
        bool ok=false;
        for(int i=0;i<tam;i++){
            ll idx=upper_bound(pos[t[i]-'a'].begin(),pos[t[i]-'a'].end(),act)-pos[t[i]-'a'].begin();
            /*dbg(t);
            dbg(idx);
            dbg(act);*/
            if(idx==(ll)pos[t[i]-'a'].size()){
                cout<<"0\n";
                ok=true;
                break;
            }
            else{
                act=pos[t[i]-'a'][idx];
            }
        }
        if(!ok){
            cout<<dp[act]<<"\n";
        }
        
    }
}