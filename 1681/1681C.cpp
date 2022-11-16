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
    vector <ll> a(n),b(n);
    FOR(i,0,n){
        cin>>a[i];
    }
    FOR(i,0,n){
        cin>>b[i];
    }
    vector <pair<ll,ll>> c;
    FOR(i,0,n){
        FOR(j,i+1,n){
            if(a[i]==a[j]){
                if(b[i]>b[j]){
                    c.push_back(mp(i+1,j+1));
                    swap(a[i],a[j]);
                    swap(b[i],b[j]);
                    continue;
                }
            }
            if(a[i]>a[j]){
                c.push_back(mp(i+1,j+1));
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
        }
    }
    if(!is_sorted(all(b))){
        cout<<"-1\n";
    }
    else{
        cout<<c.size()<<"\n";
        for(auto e :  c){
            cout<<e.first<<" "<<e.second<<"\n";
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








