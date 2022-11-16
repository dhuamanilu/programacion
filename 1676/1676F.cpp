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
    map <ll,ll> m;
    FOR(i,0,n){
        ll aux;
        cin>>aux;
        m[aux]++;
    }
    vector <ll> good;
    for(auto e : m){
        if(e.se>=k){
            good.push_back(e.f);
        }
    }
    if(!good.size()){
        cout<<"-1\n";
        return;

    }
    sort(all(good));
    ll lans=good[0],rans=good[0],mx=0,l=good[0];
    FOR(i,1,good.size()){
        if(good[i]-1==good[i-1]){
            if(good[i]-l>mx){
                lans=l;
                rans=good[i];
                mx=good[i]-l;
            }
        }
        else{
            l=good[i];
        }
    }
    cout<<lans<<" "<<rans<<"\n";


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








