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
    vector <ll> a(n,0);
    FOR(i,0,n){
        cin>>a[i];

    }

    vector <bool> b(n);
    set <ll> set1;
    ll auxi;
    FOR(i,0,n){
        cin>>auxi;
        if(auxi==1){
            b[i]=true;
            set1.insert(1);
        }
        else{
            b[i]=false;
            set1.insert(0);
        }
    }

    if((int)set1.size()==1 && is_sorted(a.begin(),a.end())){
        cout<<"YES\n";
        return;
    }
    bool cont=false,cont2=false;
    FOR(i,0,n){
        if(b[i]==false){
            cont=true;
        }
        if(b[i]==true){
            cont2=true;
        }

    }
    if(cont && cont2){
        cout<<"YES\n";
        return;
    }
    else{
        cout<<"NO\n";
        return;
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}








