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
    ll n1=(ll)s.size(),n2=(ll)t.size(),cont=0;
    if(n2>n1){
        cout<<"NO\n";
        return;
    }
    vll pos;
    ll j,k=0,q=0;
    FOR(i,(n2-n1)%2,n1){
        if(k==1){
            k=0;
            continue;
        }
        if(q<n2 && s[i]==t[q]){
            q++;
        }
        else{
            k++;
        }
    }
    if(q==n2){
        cout<<"YES\n";
    }
    else{
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








