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
    if(n==3){
        cout<<"NO\n";
        return;
    }
    if(n%2==0){
        cout<<"YES\n";
        ll temp=1;
        FOR(i,0,n){
            if(i%2==0){
                cout<<temp<<" ";
            }
            else{
                cout<<-1*temp<<" ";
            }
        }
        cout<<"\n";
    }
    else{
        cout<<"YES\n";
        FOR(i,0,n){
            if(i%2==0){
                cout<<1-(n/2)<<" ";
            }
            else{
                cout<<(n/2)<<" ";
            }
        }
        cout<<"\n";
    }
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








