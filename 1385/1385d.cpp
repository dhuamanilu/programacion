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
ll calc(string &s,char c){
    if(s.size()==1){
        return s[0]!=c;
    }
    ll mid=s.size()/2;
    string aux(s.begin(),s.begin()+mid);
    ll izq=calc(aux,c+1);
    izq-=count(s.begin()+mid,s.end(),c);
    izq+=s.size()/2;
    string aux2(s.begin()+mid,s.end());
    ll der=calc(aux2,c+1);
    der-=count(s.begin(),s.begin()+mid,c);
    der+=s.size()/2;

    return min(der,izq);

}
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    cout<<calc(s,'a')<<"\n";
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








