#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)
#define FOR1(i, a, b) for (long long i=a; i<=(b); i++)
#define mp make_pair
#define pb push_back
#define f first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200005;
const int N=1000+3;

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
        a[i]--;
    }
    vector <vector <ll> > G(n);
    FOR(i,0,n){
        ll skill;
        cin>>skill;
        G[a[i]].push_back(skill);
    }
    FOR(i,0,n){
        sort(all(G[i]),greater<ll>());
    }
    vector <vector <ll>> sumas(n,vector<long long>(1, 0));
    FOR(i,0,n){
        for(auto e : G[i]){
            sumas[i].push_back(sumas[i].back()+e);
        }
    }
    /*cout<<"Sumas : "<<sumas.size()<<"\n";
    for(vector<ll> e : sumas){
        for(ll el: e){
            cout<<el<<" ";
        }
        cout<<"\n";
    }*/
    vector <ll> ans(n,0);
    FOR(i,0,n){
        ll sz=G[i].size();
        FOR1(k,1,sz){
            ans[k-1]+=sumas[i][((sz/k)*k)];
        }
    }
    for(auto e : ans){
        cout<<e<<" ";
    }
    cout<<"\n";


}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








