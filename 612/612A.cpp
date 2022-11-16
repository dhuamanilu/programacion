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
    ll n,p,q;
    cin>>n>>p>>q;
    string s;
    cin>>s;

    FOR(i,0,(n/p)+1){
        FOR(j,0,(n/q)+1){
            if(i*p + j*q ==n){
                cout<<i+j<<"\n";
                ll pos=0;
                FOR(k,0,i){
                    cout<<s.substr(pos,p)<<"\n";
                    pos+=p;
                }
                FOR(l,0,j){
                    cout<<s.substr(pos,q)<<"\n";
                    pos+=q;
                }
                return;
            }
        }
    }
    cout<<"-1\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








