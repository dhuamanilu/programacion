#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define n_l '\n'

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int N=1000+3;
vector<vector<ll>  > guar;
void generatesubsets(vector<ll> &choices,ll current, ll K, vector<ll> selected=vector<ll>()){
    if(choices.size()-current<K-selected.size())
        return;
    if(selected.size()==K){
        vll auxi;
        for(auto i:selected)
            auxi.pb(i);
        guar.pb(auxi);
        return;
    }
    if(current==choices.size())
        return;
    selected.push_back(choices[current]);
    generatesubsets(choices,current+1,K,selected);
    selected.pop_back();
    generatesubsets(choices,current+1,K,selected);
}
void solve(){
    ll n,k,x;
    cin>>n>>k>>x;
    vll a(n);
    double sum=0;
    FOR(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }
    sum*=1.0;
    double ans=DBL_MAX;
    ans=min(ans,abs(x-(sum/n)));
    if(k>=1 && n>1){
        FOR(i,0,n){
            sum-=a[i];
            double prom=(1.0*sum)/(n-1);
            ans=min(ans,abs(prom-x));
            sum+=a[i];
        }
    }
    if(k>=2 && n>2){
        guar.clear();
        generatesubsets(a,0,n-2);
        for(auto & e : guar){
            double sum2=0;
            for(auto & e2 : e){
                sum2+=e2;
            }
            sum2*=1.0;
            sum2/=(n-2);
            ans=min(ans,abs(sum2-x));
        }
    }
    if(k>=3 && n>3){

    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}








