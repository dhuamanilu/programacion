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
    vector <pair<ll,ll>> a(n);

    FOR(i,0,n){
        ll aux;
        cin>>aux;
        a[i]=mp(aux,i);
    }
    sort(all(a));
    vector <ll> pre(n,0);
    pre[0]=a[0].f;
    FOR(i,1,n){
        pre[i]=pre[i-1]+a[i].f;
    }
    ll s=0,e=n-1,m=s+(e-s)/2,guarda=-1;
    while(s<=e){
        m=s+(e-s)/2;
        ll acum=pre[m],ind=m+1;
        while(ind<n && acum>=a[ind].f){
            acum+=a[ind++].f;
        }
        if(ind==n){
            //cout<<"guardare : "<<s<<" "<<m<<" "<<e<<"\n";
            guarda=m;
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    cout<<n-guarda<<"\n";
    vector <ll> auxiliar;
    FOR(i,guarda,n){
        auxiliar.push_back(a[i].se+1);
    }
    sort(all(auxiliar));
    for(auto e : auxiliar){
        cout<<e<<" ";
    }
    cout<<"\n";
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





