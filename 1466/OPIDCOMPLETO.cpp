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
    vector <ll> a(n,0);
    FOR(i,0,n){
        cin>>a[i];
    }
    ll i=0;
    while(i!=a.size()-1){
        if(a[i]<a[i+1]){
            a.erase(a.begin()+i);
            k--;
            if(k==0){
                //cout<<"ASDASAS";
                for(auto ele : a){
                    cout<<ele;
                }
                cout<<"\n";
                return;
            }
            i=max(i-1,0ll);
        }
        else{
            i++;
        }
    }
    a.resize(a.size()-k);
    for(auto e : a){
        cout<<e;
    }
    cout<<"\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








