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
    ll n,k;
    cin>>n>>k;
    vl a(n);
    for(auto &e :a)cin>>e;
    vl pref(n,0);
    pref[0]=a[0];
    for(ll i=1;i<n;i++){
        pref[i]=pref[i-1]+a[i];
    }
    auto get=[&](ll l,ll r){
        assert(l<=r);
        if(l<=r){
            if(l>=1){
                return pref[r]-pref[l-1];
            }
            else{
                return pref[r];
            }
        }
        /*else{
            return pref[n-1]-pref[l-1]+pref[r];
        }*/
    };
    for(ll i=0;i<n;i++){
        ll sum=i+1<=n-1 ? get(i+1,n-1) : 0ll;
        ll alfa=n-i-1;
        ll ter1=k*((alfa*(alfa+1))/2)+alfa*a[i];
        dbg(sum);
        dbg(ter1);
        if(sum>=ter1){
            if(a[i]+(n-i)*k <= a[0]){
                ll s=0,e=i,m=s+(e-s)/2;
                while(e-s>1){
                    m=s+(e-s)/2;
                    ll xd=sum+get(0,m);
                    if(xd>=(m+1+alfa)*a[i]){
                        s=m;
                    }
                    else e=m;
                }
                cout<<e+1<<"\n";
            }
            else{
                cout<<"1\n";
            }
            
        }
        else{
            ll s=i,e=n,m=s+(e-s)/2;
            while(e-s>1){
                m=s+(e-s)/2;
                ll xd=get(i,m);
                if(xd>=(m-i+1)*a[i]){
                    s=m;
                }
                else e=m;
            }
            cout<<e+1<<"\n";
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    while(t--) solve();
}