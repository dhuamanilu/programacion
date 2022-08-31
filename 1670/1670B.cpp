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
    string s;
    cin>>s;
    ll k;
    cin>>k;
    vector <ll> a(27,0);
    FOR(i,0,k){
        char auxi;
        cin>>auxi;
        a[auxi-'a']++;
    }

    FOR(i,0,n-1){
        if(a[s[i+1]-'a']){
            s[i]='1';
        }
        else{
            s[i]='0';
        }
    }
    s[n-1]='0';
    //cout<<"ESTE ES EL S : "<<s<<"\n";
    ll cont=LONG_LONG_MIN,j=0;

    FOR(i,0,n){
        if(s[i]-'0'){
            cont=max(cont,i-j);
            j=i+1;
        }
    }
    if(cont==LONG_LONG_MIN) cont=-1;
    cout<<cont+1<<"\n";


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








