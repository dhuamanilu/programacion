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
    vector <pair <ll,ll > > poderminimoYsize;
    FOR(i,0,n){
        ll k;
        cin>>k;
        vector <ll> aux(k,0);
        ll maxi=LONG_LONG_MIN,guardaIndice=0;
        FOR(j,0,k){
            cin>>aux[j];
            maxi=max(maxi,aux[j]-j);
        }
        //cout<<"maxi+1-guardaIndice y k :  "<<maxi+1-guardaIndice<<" "<<k<<"\n";
        poderminimoYsize.push_back(mp(maxi+1,k));

    }
    sort(all(poderminimoYsize));

    ll s=poderminimoYsize[0].f,e=poderminimoYsize[poderminimoYsize.size()-1].f,m=s+(e-s)/2;
    ll ans=-1;
    while(s<=e){
        //cout<<s<<" "<<e<<" "<<m<<"\n";
        m=s+(e-s)/2;
        //inicia en 1
        bool ok=true;
        ll power=m;
        FOR(k,1,poderminimoYsize.size()){
            if(power+poderminimoYsize[k-1].se < poderminimoYsize[k].f ){
                ok=false;
                break;
            }
            else{
                power+=poderminimoYsize[k-1].se;
            }
        }
        if(ok){
            ans=m;
            e=m-1;
        }
        else{
            s=m+1;
        }

    }
    cout<<ans<<"\n";
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








