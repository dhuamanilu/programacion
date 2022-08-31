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
    ll cont=0;
    FOR(i,0,s.length()){
        cont+=s[i]-'a'+1;
    }
    if(s.length()%2==0){
        cout<<"Alice "<<cont<<"\n";
        return;
    }
    else{
        ll rest=min(s[0]-'a'+1,s[s.length()-1]-'a'+1);
        if(cont>2*rest){
            cout<<"Alice "<<cont-2*rest<<"\n";
        }
        else{
            cout<<"Bob "<<2*rest-cont<<"\n";
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








