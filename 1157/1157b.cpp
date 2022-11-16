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
    string s;
    cin>>s;
    vector <ll> a(10);
    FOR(i,0,9){
        cin>>a[i];
    }
    vector<ll> ind;
    FOR(i,0,n){
        ind.emplace_back(a[s[i]-'1']-(s[i]-'0' ) );
    }
    FOR(i,0,ind.size()){
        if(ind[i]>0){
            while(i<n && ind[i]>=0){
                s[i]=char('0'+a[s[i]-'1']);
                i++;
            }
            break;
        }
    }
    cout<<s<<"\n";
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








