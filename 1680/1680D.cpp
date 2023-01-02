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
    ll a[n][2];
    vector < pair < ll,ll > > pos;
    FOR(j,0,2){
        string s;
        cin>>s;
        FOR(i,0,n){
            if(s[i]=='*'){
                a[i][j]=1;
                pos.push_back(mp(i,j));
            }
            else a[i][j]=0;
        }
    }
    sort(all(pos));
    ll mid=pos[pos.size()/2].f,sum=0;
    cout<<"es f se:"<<pos[pos.size()/2].f<<" "<<pos[pos.size()/2].se <<"\n";
    for(auto e : pos){
        sum+=abs(e.f-mid);
        if(e.se !=pos[pos.size()/2].se) sum++;
    }
    cout<<sum<<"\n";

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








