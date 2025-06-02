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
    ll n,m;
    cin>>n>>m;
    V<vl> a(n,vl(m));
    for(auto & e: a){
        for(auto &e2 : e){
            char xd;
            cin>>xd;
            e2=xd-'0';
        }
    }
    ll layer=0;
    auto next=[&](array<ll,3> xd)->array<ll,3>{
        ll x=xd[0],y=xd[1],modo=xd[2];
        if(modo==0){
            if(y+1<m-layer){
                return {x,y+1,modo};
            }
            else {
                return {x+1,y,1};
            } 
        }
        else if(modo==1){
            if(x+1<n-layer){
                return {x+1,y,modo};
            }
            else{
                return {x,y-1,2};
            }
        }
        else if(modo==2){
            if(y>=1+layer){
                return {x,y-1,modo};
            }
            else{
                return {x-1,y,3};
            }
        }
        else{
            if(x>=1+layer){
                return {x-1,y,modo};
            }
            else{
                return {x,y+1,0};
            }
        }
    };
    ll lim=min(n/2,m/2),ans=0;
    for(int i=0;i<lim;i++){
        layer=i;
        ll x=i,y=i,modo=0;
        do{
            auto coor1=next({x,y,modo});
            auto coor2=next(coor1);
            auto coor3=next(coor2);
            //auto coor4=next(coor3);
            //dbg(coor1);
            //dbg(coor2);
            //dbg(coor3);
            //dbg(coor4);
            ll ele1=a[coor1[0]][coor1[1]];
            ll ele2=a[coor2[0]][coor2[1]];
            ll ele3=a[coor3[0]][coor3[1]];
            ll ele4=a[x][y];
            /*if(j+1==(2*(n+m-2)-4*i)){
                dbg(x);
                dbg(y);
                dbg(coor1);
                dbg(coor2);
                dbg(coor3);
            }*/
            if(ele1==5 && ele2==4 && ele3==3 && ele4==1){
                //dbg(x);
                //dbg(y);
                //dbg(coor1);
                //dbg(coor2);
                //dbg(coor3);
                ans++;
            }
            x=coor1[0];
            y=coor1[1];
            modo=coor1[2];
        }while(x!=i || y!=i);
        //dbg(ans);
    }
    cout<<ans<<"\n";

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t=1;
    cin>>t;
    while(t--) solve();
}