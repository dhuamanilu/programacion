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
    ll a[n];
    set <ll> s;
    vll falta;
    FOR1(i,1,n){
        s.insert(i);
    }
    FOR(i,0,n){
        cin>>a[i];
        if(s.find(a[i])!=s.end()){
            s.erase(a[i]);
        }
        else{
            falta.push_back(a[i]);
        }
    }
    sort(all(falta));
    reverse(all(falta));
    for(auto &e :falta){
        auto it=s.end();
        it--;
        ll aux=*it;
        if(2*aux> (e-1)){
            cout<<"-1\n";
            return;
        }
        s.erase(it);

    }
    cout<<falta.size()<<"\n";

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








