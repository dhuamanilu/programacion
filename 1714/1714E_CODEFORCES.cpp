#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (long long i=a; i<(b); i++)

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
ll op(ll a){
    return a+a%10;
}
void solve(){
    ll n;
    cin>>n;
    vector <ll> a(n);
    bool flag=false;
    FOR(i,0,n){
        cin>>a[i];
        if(a[i]%5==0){
            flag=true;
            a[i]=op(a[i]);
        }
    }
    bool f2,f3;
    if(flag){
        if(*max_element(all(a))==*min_element(all(a)))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    else{
        f2=false;
        f3=false;
        FOR(i,0,n){
            ll auxi=a[i];
            while(auxi%10!=2){
                auxi=op(auxi);
            }
            if(auxi%20==2) f2=true;
            else f3=true;
        }

        if(f2 && f3){
            cout<<"NO\n";
            return;
        }
        else{
            cout<<"YES\n";
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








