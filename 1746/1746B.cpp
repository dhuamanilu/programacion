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
    vector <ll> a(n);
    bool ok=true;
    FOR(i,0,n){
        cin>>a[i];
        if(a[i]==0){
            ok=false;
        }
    }
    if(ok){
        cout<<"0\n";
        return;
    }
    ll ans=0,i=0,j=n-1;
    while(i<j){
        //cout<<"este es el i j a[i] y a[j]"<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<"\n";
        if(a[j]) j--;
        else if(a[i]){
            if(!a[j]) ans++;
            i++; j--;
        }
        else i++;
    }
    cout<<ans<<"\n";

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








