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
    int n;
    cin>>n;
    int a[n];
    map <ll,ll> m;
    priority_queue<int, vector<int> > pq;
    FOR(i,0,n){
        cin>>a[i];
        m[a[i]]++;
    }
    for(auto e : m){
        pq.push(e.se);
    }
    ll sum=n;
    while(pq.size()>=2){
        int aux=pq.top();
        aux--;
        pq.pop();
        int aux2=pq.top();
        aux2--;
        pq.pop();
        sum-=2;
        if(aux){
            pq.push(aux);
        }
        if(aux2){
            pq.push(aux2);
        }
    }
    cout<<sum<<"\n";
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








