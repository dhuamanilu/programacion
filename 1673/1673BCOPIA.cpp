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
    string s;
    cin>>s;
    set<ll> set1;
    FOR(i,0,s.length()){
        set1.insert(s[i]-'a');
    }
    int sz=(int)set1.size();
    FOR(i,sz,s.length()){
        if(s[i]!=s[i-sz]){
            cout<<"NO\n";
            return;
        }
    }
    set1.clear();
    FOR(i,0,sz){
        set1.insert(s[i]);
    }
    if(set1.size()<sz)
        cout<<"NO\n";
    else
        cout<<"YES\n";
    return;



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








