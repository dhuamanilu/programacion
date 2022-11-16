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

// https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/
void subsetsUtil(vector<ll>& A, vector<vector<ll> >& res,
                 vector<ll>& subset, ll index){
    res.push_back(subset);
    for (ll i = index; i < A.size(); i++) {
        subset.push_back(A[i]);
        subsetsUtil(A, res, subset, i + 1);
        subset.pop_back();
    }
    return;
}
vector<vector<ll> > subsets(vector<ll>& A){
    vector<ll> subset;
    vector<vector<ll> > res;
    ll index = 0;
    subsetsUtil(A, res, subset, index);
    return res;
}
void solve(map <ll,ll> &m){
    ll n;
    cin>>n;
    for(auto e : m){
        if(e.first>=n){
            cout<<e.first<<"\n";
            return;
        }
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> arr = {0,1,2,3,4,5,6,7,8,9};
    vector<vector<ll>> res = subsets(arr);
    map <ll,ll> m;
    for(ll i=0;i<res.size();i++){
        ll auxi=0;
        for(ll j=0;j<res[i].size();j++){
            auxi+=pow(3,res[i][j]);
        }
        m[auxi]++;
    }
    int t=1;
    cin>>t;
    while(t--){
        solve(m);
    }
    return 0;
}








