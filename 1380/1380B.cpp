#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
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
    ll n=s.size(),contS=0,contR=0,contP=0;
    FOR(i,0,n){
        if(s[i]=='S') contS++;
        else if(s[i]=='R') contR++;
        else contP++;
    }
    if(contS==0 && contR==0){
        string aux(n,'S');
        cout<<aux<<"\n";
    }
    else if(contR==0 && contP==0){
        string aux(n,'R');
        cout<<aux<<"\n";
    }
    else if(contS==0 && contP==0){
        string aux(n,'P');
        cout<<aux<<"\n";
    }
    else{
        if(contS>=contR && contS>=contP){
            string aux(n,'R');
            cout<<aux<<"\n";
        }
        else if(contR>=contS && contR>=contP){
            string aux(n,'P');
            cout<<aux<<"\n";
        }
        else{
            string aux(n,'S');
            cout<<aux<<"\n";
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








