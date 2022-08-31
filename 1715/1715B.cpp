#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)
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
    ll n,k,b,s;
    cin>>n>>k>>b>>s;
    if(n==1){
        if(floor(s/k)!=b){
            cout<<"-1\n";
            return;
        }
    }
    if(floor(s/k)==b){
        FOR(i,0,n-1){
            cout<<"0 ";
        }
        cout<<s<<"\n";
        return;
    }
    if (floor((s-(n-1)*(k-1))/k) > b ||(floor(s/k)<b)){
        cout<<"-1\n";
        return;
    }
    ll a[n];
    ll auxi=0,guarsuma=s;
    bool ok=false;
    FOR(i,0,n){
        a[i]=k-1;
        auxi+=a[i];
        if(floor ((guarsuma-auxi)/k)==b){
            FOR(j,i+1,n-1){
                a[j]=0;
            }
            ok=true;
        }
        if(ok) break;
    }
    a[n-1]=(guarsuma-auxi);
    FOR(i,0,n){
        cout<<a[i]<<" ";
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
    // 3 5 4 7 39 5 4 7 40 5 4 7 41
    return 0;
}








