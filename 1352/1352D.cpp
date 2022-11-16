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
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll mov=0,i=0,j=n-1,acA=0,acB=0,antA=0,antB=0,sumA=0,sumB=0;
    while(i<=j){
        //cout<<" I J antes turno alice"<<i<<" "<<j<<"\n";
        bool ok1=false;
        while(i<=j && acA<=antB && i<n){
            ok1=true;
            acA+=a[i++];
        }
        if(ok1)
            mov++;
        antA=acA;
        sumA+=acA;
        //cout<<" I J antes turno bob"<<i<<" "<<j<<"\n";
        bool ok2=false;
        while(i<=j && acB<=antA && j>0){
            ok2=true;
            acB+=a[j--];
        }
        if(ok2) mov++;
        antB=acB;
        sumB+=acB;
        acA=0;
        acB=0;
    }
    cout<<mov<<" "<<sumA<<" "<<sumB<<"\n";

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








