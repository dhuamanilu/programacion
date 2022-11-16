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
    string a,b;
    cin>>a>>b;
    if(a!=b){
        FOR(i,0,n){
            if(a[i]-'0' + b[i]-'0' != 1){
                cout<<"NO\n";
                return;
            }
        }
        vector <pair<ll,ll > > ans;
        FOR(i,0,n){
            ll j=i;
            while(a[j]=='0' && j<n){
                j++;
            }
            if(i==j) continue;
            ans.push_back(mp(i+1,j));
            i=j-1;
        }
        if(ans.size()%2==0){
            ans.push_back(mp(1,n));
        }
        else{
            ans.push_back(mp(1,(ll)n/2));
            ans.push_back(mp((ll)(n/2)+1,n));
        }
        cout<<"YES\n";
        cout<<ans.size()<<"\n";
        for(auto e : ans){
            cout<<e.f<<" "<<e.se<<"\n";
        }
    }
    else{
        vector <pair<ll,ll > > ans;
        ans.push_back(mp(1,n));
        FOR(i,0,n){
            if(a[i]=='0') a[i]='1';
            else a[i]='0';
        }
        //cout<<"este es el a despeus de tandfomrar : "<<a<<"\n";
        FOR(i,0,n){
            ll j=i;
            while(a[j]=='0' && j<n){
                j++;
            }
            if(i==j) continue;
            ans.push_back(mp(i+1,j));
            i=j-1;
        }
        if((ans.size()-1)%2==0){
            ans.push_back(mp(1,n));
        }
        else{
            ans.push_back(mp(1,(ll)n/2));
            ans.push_back(mp((ll)(n/2)+1,n));
        }
        cout<<"YES\n";
        cout<<ans.size()<<"\n";
        for(auto e : ans){
            cout<<e.f<<" "<<e.se<<"\n";
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








