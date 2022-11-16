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

ll isprime(ll N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}
void solve(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<"FastestFinger\n";
        return;
    }
    if(n==2){
        cout<<"Ashishgup\n";
        return;
    }
    if(n%2==1){
        cout<<"Ashishgup\n";
        return;
    }
    else{
        ll num=n,cont=0;
        while(num%2==0){
            num/=2;
            cont++;
        }
        if(num==1){
            cout<<"FastestFinger\n";
            return;
        }

        if(isprime(num) && cont<=1){
            cout<<"FastestFinger\n";
            return;
        }
        else{
            cout<<"Ashishgup\n";
            return;
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








