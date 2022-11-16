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

void solve(){
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    vector <ll> pre1(n,0),pre2(n,0);
    pre1[0]=(a[0]=='1');
    pre2[0]=(a[0]=='0');
    FOR(i,1,n){
       pre1[i]=pre1[i-1]+(a[i]=='1');
       pre2[i]=pre2[i-1]+(a[i]=='0');
    }
    FOR(i,0,n){
        if(pre1[i]!=pre2[i] && ( (a[i]==b[i])!=(a[i+1]==b[i+1]) ) ){
            //cout<<i<<" "<<pre1[i]<<" "<<pre2[i]<<"\n";
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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








