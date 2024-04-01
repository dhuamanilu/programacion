#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "../debugICPC.h"
#define chk(...) if (!(__VA_ARGS__)) cerr << "\033[41m" << "Line(" << __LINE__ << ") -> function(" \
	 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\033[0m" << "\n", exit(0);

#define MACRO(code) do {code} while (false)
#define RAYA MACRO(cerr << "\033[101m" << "================================" << "\033[0m" << endl;)
#else
#define dbg(...)

#define chk(...)
#define RAYA
#endif
using ll= long long;
using vs = vector<string>;
using vl=vector<long long>;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define each(a,x) for (auto& a: x)

const int N=100000+5;
vector<vl> vis(2,vl(N,0));
vector<vl> id(2,vl(N,0));
vl dx={1,-1,0,0};
vl dy={0,0,1,-1};
ll n;
bool isValid(ll x,ll y){
    return x>=0 && x<2 && y>=0 && y<n;
}
void dfs(ll i,ll j,ll idx){
    vis[i][j]=true;
    id[i][j]=idx;
    FOR(it,0,4){
        ll newX=i+dx[it],newY=j+dy[it];
        if(isValid(newX,newY)){
            if(!vis[newX][newY]){
                dfs(newX,newY,idx);
            }
        }
    }
}
void solve() {
	cin>>n;
    FOR(i,0,n){
        vis[0][i]=0;
        id[0][i]=0;
        vis[1][i]=0;
        id[1][i]=0;
    }
	vs a(2);
	each(e,a) cin>>e;
    ll idx=1;   
    FOR(i,0,2){
        FOR(j,0,n){
            if(!vis[i][j]){
                dfs(i,j,idx);
                idx++;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;

    for(int idx = 0; idx < t; idx++) {
        solve();
    }
}








