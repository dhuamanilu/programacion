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
    string s,t;
    cin>>s>>t;
    ll n1=(ll)s.size(),n2=(ll)t.size();
    bool ok=false;
    FOR(pos,0,n1){
        FOR(izq,0,n1-pos){
            if(izq>=n2 || s[pos+izq]!=t[izq]) break;
            ll k=n2-izq-1;
            if(pos+izq<k) continue;
            ll l1=pos;
            ll r1=pos+izq;
            ll l2=r1-k;
            string aux=s.substr(l2,k);
            reverse(all(aux));
            string aux2=s.substr(l1,izq+1);
            if(aux2+aux==t){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
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








