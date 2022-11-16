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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string ans="";
    vector <ll> cont(25,0);
    FOR(i,0,n){
        cont[s[i]-'a']++;
    }
    FOR(i,0,k){
        ll j=0;
        while(j<n/k){
            if(cont[j]>0){j++; continue; }
            else break;
        }
        if(j==n/k){
            FOR(l,0,n/k){
                cont[l]--;
            }
            ans+=char('a'+j);
        }
        else{
            ll aux=0;
            FOR(m,0,j){
                aux++;
                cont[m]--;
            }
            ll pos=j-1;
            /*while(aux<n/k){
                if(cont[pos]<=0){
                    pos--;
                }
                else{
                    cont[pos]--;
                    aux++;
                }
            }*/
            ans+=char('a'+pos+1);
        }
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








