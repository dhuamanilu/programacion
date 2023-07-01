#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map <ll,ll> mll;
typedef vector <pair<ll,ll>> vpll;
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
    ll maxi=LONG_LONG_MIN;
    FOR(i,0,n){
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    ll cont=0;
    vector<bool> used(n+1,false);
    FOR(i,0,min(n,maxi)){
        //cout<<"este a en isera marcaros:"<<a[i]<<"\n";
        used[a[i]]=true;
    }
    bool ok=true;
    FOR1(i,1,maxi){
        if(!used[i]){
            //cout<<"FALLO EL TEST"<<i<<"\n";
            ok=false;
            break;
        }
    }
    vector <bool> used2(n+1,false);
    FOR(i,maxi,n){
        used2[a[i]]=true;
    }
    FOR1(i,1,n-maxi){
        if(!used2[i]){
            ok=false;
            break;
        }
    }
    vpll ans;
    if(ok){
        ans.pb({maxi,n-maxi});
    }

    ok=true;
    vector <bool> used3(n+1,false);
    FOR(i,0,n-maxi){
        used3[a[i]]=true;
    }
    FOR1(i,1,n-maxi){
        if(!used3[i]){
            ok=false;
            break;
        }
    }

    vector <bool> used4(n+1,false);
    FOR(i,n-maxi,n){

        used4[a[i]]=true;
    }
    FOR1(i,1,maxi){
        if(!used4[i]){

            ok=false;
            break;
        }
    }

    if(ok){
        ans.pb({n-maxi,maxi});
    }
    if((ll)ans.size()==0){
        cout<<"0\n";
    }
    else{
        cout<<ans.size()<<"\n";
        for(auto e :  ans){
            cout<<e.f<<" "<<e.se<<"\n";
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
