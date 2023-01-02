#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


typedef pair<int, int> pi;

typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a, b) for (int i=a; i<(b); i++)

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

ll intersect(vector <ll> &v ,ll m){
    ll inter=0;
    FOR(i,0,v.size()-1){
        if(v[i+1]< v[i]+m-1 ){
            inter+=v[i]+m-v[i+1] ;
        }
    }
    return inter;
}
ll bb(ll h,vector <ll> &v){
    ll s=0,e=h,m=s+(e-s)/2;
    ll best=0;
    while(s<e){
        cout<<"m : "<<m<<"\n";
        cout<<"s : "<<s<<"\n";
        cout<<"e : "<<e<<"\n";
        m=s+(e-s)/2;
        if(v.size()*m - intersect(v,m) >=h){
            best=m;
            e=m;
        }
        else if(v.size()*m <h){
            s=m+1;
        }
    }
    return best;
}
void solve(){
    ll n,h;
    cin>>n>>h;
    vector <ll> a(n);
    FOR(i,0,n){
        cin>>a[i];
    }
    cout<<bb(h,a)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*if (fopen("abcd.in", "r")) {
		freopen("billboard.in", "r", stdin);
		freopen("billboard.out", "w", stdout);
    }*/
  	int t=1;
    cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}
