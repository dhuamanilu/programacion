#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
typedef priority_queue<ll> pq;
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
#define n_l '\n'
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;

void solve(){
    string x,y;
    cin>>x>>y;
    map<string,ll> m;
    m["N"]=0;
    m["NE"]=45;
    m["E"]=90;
    m["SE"]=135;
    m["S"]=180;
    m["SW"]=225;
    m["W"]=270;
    m["NW"]=315;
    ll n=x.size();
    double ans=m[x.substr(n-2)];

    for(ll i=n-3;i>=0;i--){
        ans=(ans+m[to_string(x[i])])/2;

    }
    n=y.size();
    double ans2=m[y.substr(n-2)];
    for(ll i=n-3;i>=0;i--){
        ans2=(ans2+m[to_string(y[i])])/2;
    }
    double res=min(abs(ans-ans2),360-abs(ans-ans2));
    if(ans<ans2){
        res=180-res;
    }
    cout<<res<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}








