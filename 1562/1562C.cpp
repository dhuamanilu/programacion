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
    string s;
    cin>>s;
    ll cont1=0;
    FOR(i,0,n){
        cont1+=(s[i]=='1');
    }
    if(cont1==n){
        cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<"\n";
    }
    else{
        FOR(i,0,n){
            if(s[i]=='0'){
                if(i<(n)/2){
                    cout<<i+2<<" "<<n<<" "<<i+1<<" "<<n<<"\n";
                }
                else{
                    cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<"\n";
                }
                break;
            }
        }
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








