#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
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
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    mll m;
    FOR(i,0,n){
        cin>>a[i];
        m[a[i]]++;
    }
    if(m[1]>1){
        cout<<"NO\n";
        return;
    }
    for(auto e : m){
        if(e.se>2){
            cout<<"NO\n";
            return;
        }
    }
    ll guarda=0;
    vector<bool> vis(n+1,false);
    vll ans1(n,-1),ans2(n,-1);
    set <ll> s1,s2;
    FOR1(i,1,n){
        s1.insert(i);
        s2.insert(i);
    }
    FOR(i,0,n){
        if(vis[a[i]]){
            ans2[i]=a[i];
            s2.erase(a[i]);
            vis[a[i]]=true;
        }
        else{
            ans1[i]=a[i];
            s1.erase(a[i]);
            vis[a[i]]=true;
        }
    }
    FOR(i,0,n){
        if(ans2[i]!=-1) continue;
        auto x=s2.lower_bound(ans1[i]);
        //cout<<*x<<"\n";
        if(x==s2.end()){
            x--;
        }
        //cout<<*x<<"\n";
        ans2[i]=*x;
        s2.erase(x);
    }

    FOR(i,0,n){
        if(ans1[i]!=-1) continue;
        auto x=s1.lower_bound(ans2[i]);
        //cout<<*x<<"\n";
        if(x==s1.end()){
            x--;
        }
        ans1[i]=*x;
        s1.erase(x);
    }
    cout<<"YES\n";
    for(auto e : ans1){
        cout<<e<<" ";
    }
    cout<<"\n";
    for(auto e : ans2){
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








