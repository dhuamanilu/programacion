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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans=0,losses=0,wins=0,cont=0;
    vll streaks;
    FOR(i,0,n){
        if(s[i]=='L'){
            losses++;
            if(i==0 || (i>0 && s[i-1]=='W')){
                streaks.pb(0);
            }
            streaks.back()++;
        }
        else{
            wins++;
            if(i==0 || (i>0 && s[i-1]=='L')) cont++;
        }
    }
    if(k>=losses){
        cout<<2*n-1<<"\n";
    }
    else if(wins==0){
        if(k==0){
            cout<<"0\n";
        }
        else{
            cout<<2*k-1<<"\n";
        }
    }
    else{
        if(s[0]=='L'){
            streaks[0]=LONG_LONG_MAX;
        }
        if(s[n-1]=='L'){
            streaks.back()=LONG_LONG_MAX;
        }
        sort(all(streaks));
        wins+=k;
        for(auto e : streaks){
            if(e>k) break;
            k-=e;
            cont--;
        }
        cout<<2*wins-cont<<"\n";
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








