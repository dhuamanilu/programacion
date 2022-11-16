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
    ll W,H,x1,y1,x2,y2,w,h;
    cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
    ll ans=LONG_LONG_MAX;
    if(h<y1 || h<H-y2 || w<x1 || w<W-x2){
        cout<<"0\n";
        return;
    }
    if(y2+(h-y1)<=H){
        ans=min(ans,h-y1);
    }
    if(y1-(h-(H-y2))>=0){
        ans=min(ans,h-(H-y2));
    }
    if(x2+(w-x1)<=W){
        ans=min(ans,w-x1);
    }
    if(x1-(w-(W-x2))>=0){
        ans=min(ans,w-(W-x2));
    }
    if(ans==LONG_LONG_MAX){
        cout<<"-1\n";
        return;
    }
    double res=ans*1.0;
    cout<<fixed<<std::setprecision(6)<<res<<"\n";

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








