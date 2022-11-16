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
const int MX = 100001;
const int N=1000+3;

void solve(){
    ll n;
    cin>>n;
    map<ll,ll> a;
    ll mini=LONG_LONG_MAX,maxi=LONG_LONG_MIN;
    FOR(i,0,4*n){
        ll auxi;
        cin>>auxi;
        a[auxi]++;
        mini=min(mini,auxi);
        maxi=max(maxi,auxi);
    }
    ll ar=mini*maxi;
    for(auto &e : a){
        //cout<<e.first<<" "<<e.second<<"\n";
        if(e.second==0) continue;
        while(ar%e.first==0 && a.count(ar/e.first) && a[ar/e.first] >=2 && e.second>=2){
            e.second-=2;
            a[ar/e.first]-=2;
        }

    }
    for(auto e : a){
        if(e.second>0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

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








