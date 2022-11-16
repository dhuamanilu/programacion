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
    ll hc,dc,hm,dm,k,w,a;
    cin>>hc>>dc;
    cin>>hm>>dm;
    cin>>k>>w>>a;
    ll myatt=(hm+dc-1)/dc;
    ll youratt=(hc+dm-1)/dm;
    if(myatt<=youratt){
        cout<<"YES\n";
        return;
    }
    else{
        FOR(i,0,k+1){
            ll nhc=hc+i*a;
            ll ndc=dc+(k-i)*w;
            ll myatt2=(hm+ndc-1)/ndc;
            ll youratt2=(nhc+dm-1)/dm;
            if(myatt2<=youratt2){
                cout<<"YES\n";
                return;
            }
        }
        cout<<"NO\n";
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








