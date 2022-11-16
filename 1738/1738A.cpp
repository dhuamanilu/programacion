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
    ll b[n];
    FOR(i,0,n){
        cin>>b[i];
    }
    vector <ll> cero,uno;
    FOR(i,0,n){
        if(a[i]==0){
            cero.push_back(b[i]);
        }
        else uno.push_back(b[i]);
    }
    sort(all(cero));
    sort(all(uno));
    reverse(all(uno));
    ll sum=0;
    bool ok=false;
    ll j=0;
    FOR(i,0,uno.size()){
        if(i%2==0){
            if(ok){
                sum+=uno[i]*2;
                ok=false;
            }
            else
                sum+=uno[i];
        }
        else{
            if(!ok){
                ok=true;
            }
            if(j==cero.size()){
                //algo;
                for(ll k=i;k<uno.size();k++){
                    sum+=uno[i];
                }
                break;
            }
            sum+=cero[j]*2;
            j++;

        }
    }
     sort(all(cero));
    sort(all(uno));
    reverse(all(cero));
    ll sum2=0;
    bool ok2=false;
    ll j2=0;
    FOR(i2,0,cero.size()){
        if(i2%2==0){
            if(ok2){
                sum2+=cero[i2]*2;
                ok2=false;
            }
            else
                sum2+=cero[i2];
        }
        else{
            if(!ok2){
                ok2=true;
            }
            if(j2==uno.size()){
                //algo;
                for(ll k=i2;k<cero.size();k++){
                    sum2+=cero[i2];
                }
                break;
            }
            sum2+=uno[j2]*2;
            j2++;

        }
    }
    cout<<max(sum,sum2)<<"\n";
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








