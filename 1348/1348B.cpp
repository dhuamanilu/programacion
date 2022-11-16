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
    ll n,k;
    cin>>n>>k;
    ll a[n];
    set <ll> s;
    FOR(i,0,n){
        cin>>a[i];
        s.insert(a[i]);
    }

    if(n==k){
        cout<<n<<"\n";
        FOR(i,0,n){
            cout<<a[i]<<" \n"[i==n-1];
        }
        return;
    }
    if(s.size()>k){
        cout<<"-1\n";
        return;
    }
    cout<<n*k<<"\n";
    FOR(i,0,n){
        for(auto e : s){
            cout<<e<<" ";
        }
        FOR(i,0,k-s.size()){
            cout<<"1 ";
        }
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








