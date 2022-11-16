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
    vector< vector < ll > > a;
    FOR1(i,1,n){
        vector<ll> auxi;
        FOR1(j,1,i){
                if(j==1 || j==i){
                    auxi.emplace_back(1);
                }
                else{
                    auxi.emplace_back(0);
                }
        }
        a.push_back(auxi);
        auxi.clear();
    }
    FOR(i,0,n){
        for(auto e : a[i]){
            cout<<e<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    if (fopen("a.in", "r")){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    }
    while(t--){
        solve();
    }
    return 0;
}








