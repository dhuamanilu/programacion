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
mt19937 rng(0); // or mt19937_64
ll rng_ll(ll L, ll R) { assert(L <= R);
	return uniform_int_distribution<ll>(L,R)(rng);  }

const ll BIG=(ll)1e18;
array<ll,3> brute(array<ll,3> ele){
    ll a=ele[0],b=ele[1],c=ele[2];
    
    array<ll,3> ans={BIG,BIG,BIG};
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            ll z=a-i-j;
            
            if((i*j*z)==b && (i*i+j*j+z*z)==c){
                array<ll,3> cand={i,j,z};
                sort(cand.begin(),cand.end());
                ans=min(ans,cand);
            }
        }
    }
    array<ll,3> ver={BIG,BIG,BIG};
    if(ans==ver) ans={-1,-1,-1};
    return ans;
}
array<ll,3> solve(array<ll,3> ele){
    ll a=ele[0],b=ele[1],c=ele[2];
    ll lim1=(ll)cbrt(b)+5;
    ll lim2=sqrtl(c)+5;
    ll lim3=a+5;
    ll limi=min(lim1,min(lim2,lim3));
    bool ok=false;
    array<ll,3> ans={BIG,BIG,BIG};
    auto isSquare=[](ll num){
        ll raiz=sqrtl(num);
        return (raiz*raiz)==num;
    };
    for(int i=-limi;i<=limi;i++){
        if(b%i) continue;
        ll lim4=a-i;
        ll lim5=sqrtl(b/i)+5;
        if(c-i*i < 0) continue;
        ll lim6=sqrtl(c-i*i)+5;
        ll xd=min(lim4,min(lim5,lim6));
        for(int j=i+1;j<=xd;j++){
            if(b%(i*j)) continue;
            if(c-(i*i)-(j*j) < 0) continue;
            if(!isSquare(c-(i*i)-(j*j))) continue;
            ll x1=a-i-j,x2=b/(i*j),x3=sqrtl(c-(i*i)-(j*j));
            if(x1 == x2 && x2==x3 && j<=x1){
                array<ll,3> cand={i,j,x1};
                sort(cand.begin(),cand.end());
                ans=min(ans,cand);
                ok=true;
                break;
            }
        }
        if(ok) break;
    }
    array<ll,3> ver={BIG,BIG,BIG};
    if(ans==ver) ans={-1,-1,-1};
    return ans;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    while(0){
        ll a=rng_ll(1,10000),b=rng_ll(1,10000),c=rng_ll(1,10000);
        array<ll,3> data={a,b,c};
        auto ans1=solve(data);
        auto ans2=brute(data);
        if(ans1!=ans2){
            dbg(data);
            dbg(ans1);
            dbg(ans2);
            assert(false);
        }
        else dbg("ok");
    }
    cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        array<ll,3> data={a,b,c};
        auto ans1=solve(data);
        if(ans1[0]==-1){
            cout<<"No solution.\n";
        }
        else{
            for(auto &e : ans1){
                cout<<e<<" ";
            }
            cout<<"\n";
        }
    }
}