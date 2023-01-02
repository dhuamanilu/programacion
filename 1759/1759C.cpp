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
    ll l,r,x;
    cin>>l>>r>>x;
    ll a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"0\n";
        return;
    }
    if(a+x > r && a-x < l || ( b-x<l && b + x > r)){
        cout<<"-1\n";
        return;
    }

    if(abs(a-b)>=x && (a+x<=r || a-x>=l)) {
        cout<<"1\n";
    }
    else if( (a-l>=x && r-a>=x) || (a-x<l && r>=b+x) || (r<a+x && b-x>=l) ){
        cout<<"2\n";
    }
    else{
        cout<<"3\n";
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








