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

void solve(){
    ll n,m;
    cin>>n>>m;
    ll a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    ll prefixA[n];
    prefixA[0]=0;
    FOR(i,1,n){
        prefixA[i]=prefixA[i-1]+  ((a[i] > a[i-1] ) ? 0LL : a[i-1]-a[i]);
    }
    /*cout<<"prefix1 adelat :\n";
    FOR(i,0,n){
        cout<<prefixA[i]<<" ";
    }
    cout<<nl;*/
    ll pre2[n];
    pre2[n-1]=0;
    for(ll i=n-2;i>=0;i--){
        pre2[i]=pre2[i+1]+  ((a[i] > a[i+1])? 0LL : a[i+1]-a[i]);
    }
    /*cout<<"prefix2 atras :\n";
    for(int i=n-1;i>=0;i--){
        cout<<pre2[i]<<" ";
    }*/
    cout<<nl;
    FOR(i,0,m){
        ll s,t;
        cin>>s>>t;
        s--;
        t--;
        //cout<<" s y t: "<<s<<" "<<t<<"\n";
        if(s<=t){
            ll res=prefixA[t]-(prefixA[s]);
            cout<<res<<" \n";
        }
        else{
            ll res=pre2[t]-pre2[s];
            cout<<res<<"\n";
        }

    }
/*
9 2 9 2 3 1 5 6 7 8 4 4 8 4 8*/



}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*if (fopen("abcd.in", "r")) {
		freopen("billboard.in", "r", stdin);
		freopen("billboard.out", "w", stdout);
    }*/
  	int t=1;
    //cin>>t;

  	while(t--){
        solve();
  	}
	return 0;
}
