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
    ll n,m;
    cin>>n>>m;
    ll cont2=0,cont5=0;
    while(n%2==0){
        cont2++;
        n/=2;
    }
    while(n%5==0){
        cont5++;
        n/=5;
    }
    ll mult=1;
    if(cont2==cont5){
        bool ok=false;
        while(mult<=m){
            mult*=10;
            ok=true;
        }
        if(ok) mult/=10;
        m/=mult;
        mult*=(m/10)*10;
        cout<<n*mult<<"\n";
    }
    else if(cont2<cont5){
        if(pow(2,cont5-cont2) <= m ){
            mult*=cont5-cont2;
            bool ok=false;
            while(mult<=m){
                mult*=10;
                ok=true;
            }
            if(ok) mult/=10;
            cout<<n*mult<<"\n";
        }
        else{
            ll tot=1;
            while(tot<=m){
                tot*=2;
            }
            tot/=2;

            mult*=tot;
            bool ok=false;
            while(mult<=m){
                mult*=10;
                ok=true;
            }
            if(ok) mult/=10;
            cout<<n*mult<<"\n";
        }
    }
    else{
        if(pow(2,cont2-cont5) <= m ){
            bool ok=false;
            mult*=cont2-cont5;
            while(mult<=m){
                mult*=10;
                ok=true;
            }
            if(ok) mult/=10;
            cout<<n*mult<<"\n";
        }
        else{
            ll tot=1;
            while(tot<=m){
                tot*=5;
            }
            tot/=5;
            mult*=tot;

            bool ok=false;
            while(mult<=m){
                mult*=10;
                ok=true;
            }
            if(ok) mult/=10;
            cout<<n*mult<<"\n";

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








