#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
typedef priority_queue<ll> pq;
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
    vll pos(n+1);
    FOR(i,0,n){
        cin>>a[i];
        a[i]--;
        pos[a[i]]=i;
    }
<<<<<<< HEAD
    ll s=0,e=n/2,m=s+(e-s)/2,guarda=0;
    while(s<=e){
        m=s+(e-s)/2;
        bool ok=true;
        FOR(i,m,n-m-1){
            if(pos[i]>pos[i+1]){
                ok=false;
                break;
            }
        }
        if(ok){
            guarda=m;
            s=m+1;
        }
        else{
            e=m-1;
        }
    }
    cout<<guarda<<"\n";
=======
    ll l=0,r=0;
    while(true){

    }

>>>>>>> c630fefcf3e30e3ae4cfb7ad0283d0a177c7fc06

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








