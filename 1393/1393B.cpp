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
    vector<ll> a(100005,0);
    ll sum=0,sum4=0;
    FOR(i,0,n){
        ll auxi;
        cin>>auxi;
        sum-=a[auxi]/2;
        sum4-=a[auxi]/4;
        a[auxi]++;
        sum+=a[auxi]/2;
        sum4+=a[auxi]/4;
    }
    ll q;
    cin>>q;
    FOR(i,0,q){
        string s;
        cin>>s;
        ll in;
        cin>>in;
        sum-=a[in]/2;
        sum4-=a[in]/4;

        if(s[0]=='-'){
            a[in]--;
        }
        else{
            a[in]++;
        }
        sum+=a[in]/2;
        sum4+=a[in]/4;
        if(sum>=4 && sum4>=1){
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }

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








