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
    ll n,w;
    cin>>n>>w;
    vector<ll> f(20,0);
    FOR(i,0,n){
        ll auxi;
        cin>>auxi;
        f[log2(auxi)]++;
    }
    ll libre=w,altura=1;
    FOR(i,0,n){
        ll largo=-1;
        for(int i=19;i>=0;i--){
            if(f[i] && (1<<i)<=libre){
                largo=i;
                break;
            }
        }
        if(largo==-1){
            altura++;
            libre=w;
            for(int k=19;k>=0;k--){
                if(f[k] && (1<<k)<=libre){
                    largo=k;
                    break;
                }
            }
        }
        libre-=(1<<largo);
        f[largo]--;
    }
    cout<<altura<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}








