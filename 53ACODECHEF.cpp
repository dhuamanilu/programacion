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

template<class T>
ostream& operator<<(ostream& os, vector<T> v){
    os<<"[";
    for(int i=0; i<v.size(); i++){
        os<<v[i];
        if(i!=v.size()-1){
            os<<", ";
        }
    }
    os<<"]";
    //cout<<endl;
    return os;
}

void solve(){
    ll n,w;
    cin>>n>>w;
    ll a[n];
    vector<ll> c(20,0);
    FOR(i,0,n){
        cin>>a[i];
        c[log2(a[i])]++;
    }
    cout<<c<<"\n";

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








