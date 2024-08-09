#include <iostream>
#include <vector>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// building blocks

struct connection{
    long long hub1,hub2,len;
};
const int N=10000;
vector<long long> vis(N,0);
vector<vector<long long>> G(N);
void dfs(long long x){
    vis[x]=true;
    for(auto e : G[x]){
        if(!vis[e]) dfs(e);
    }
}
void solve() {
	long long n,k;
	cin>>n>>k;
	vector<connection> a(k);
    
    set<long long> se;
    for(int i=0;i<k;i++){
        cin>>a[i].hub1>>a[i].hub2>>a[i].len;
        a[i].hub1--;
        a[i].hub2--;
        se.insert(a[i].len);
    }
    sort(a.begin(),a.end(),[&](connection c, connection d){
        return c.len<d.len;
    });
    vector <long long> values;
    for(auto e : se)values.push_back(e);
    long long s=0,e=(long long)values.size()-1,m=s+(e-s)/2,guarda=-1;
    /*
    7 11
    1 2 7
    1 4 5
    2 4 9
    2 3 8
    2 5 7
    3 5 5
    4 5 15
    4 6 6
    5 6 8
    5 7 9
    6 7 11
    */
    while(s<=e){
        m=s+(e-s)/2;
        for(int i=0;i<n;i++){
            vis[i]=false;
            G[i].clear();
        }
        for(int i=0;i<k;i++){
            if(a[i].len <= values[m]){
                long long u=a[i].hub1,v=a[i].hub2;
                G[u].push_back(v);
                G[v].push_back(u);
            }
            else break;
            
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
            if(ans>=2) break;
        }
        if(ans==1){
            guarda=m;
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    long long idx=-1;
    for(int i=0;i<k;i++){
        if(a[i].len <= a[guarda].len){
            idx=i;
        }
        else break;
    }
    cout<<a[guarda].len<<"\n";
    cout<<idx+1<<"\n";
    for(int i=0;i<idx+1;i++){
        cout<<a[i].hub1+1<<" "<<a[i].hub2+1<<"\n";
    }
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    for(int idx = 0; idx < t; idx++) {
        solve();
    }
}








