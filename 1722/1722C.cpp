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
    string a[3][n];
    FOR(i,0,3){
        FOR(j,0,n){
            cin>>a[i][j];
        }
    }
    map <string,ll> ma;
    FOR(i,0,3){
        FOR(j,0,n){
            ma[a[i][j]]++;
        }
    }
    vector <ll> res(3,0);
    FOR(i,0,3){
        FOR(j,0,n){
            if(ma[a[i][j]]==1){
                res[i]+=3;
            }
            if(ma[a[i][j]]==2){
                res[i]+=1;
            }
        }
    }
    FOR(i,0,3){
        cout<<res[i]<<" ";
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








