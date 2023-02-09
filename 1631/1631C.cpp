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
    if(4*k>n*(n-2)){
        cout<<"-1\n";
    }
    else{
        if(k==0){
            ll cont=n-1;
            FOR(i,0,n/2){
                cout<<i<<" "<<cont<<"\n";
                cont--;
            }
        }
        else if(4*k==n*(n-2)){
            ll aux=0;
            FOR(i,0,n/2){
                cout<<aux<<" "<<aux+1<<"\n";
                aux+=2;
            }
        }
        else if(k==n-1){
            if(n==4){
                cout<<"-1\n";
            }
            else{
                vll a(n/2),b(n/2);
                a[0]=n-2;
                b[0]=n-1;
                a[1]=1;
                b[1]=n-3;
                a[2]=0;
                b[2]=2;
                FOR(i,3,n/2){
                    a[i]=i;
                    b[i]=i^(n-1);
                }
                FOR(i,0,n/2){
                    cout<<a[i]<<" "<<b[i]<<"\n";
                }
            }
        }
        else{
            vll a(n/2),b(n/2);
            ll small=min(k,k^(n-1));
            FOR(i,0,n/2){
                if(i!=0 && i!=small){
                    a[i]=i;
                    b[i]=i^(n-1);
                }
            }
            a[0]=0;
            b[0]=k^(n-1);
            a[small]=k;
            b[small]=n-1;
            FOR(i,0,n/2){
                cout<<a[i]<<" "<<b[i]<<"\n";
            }
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








