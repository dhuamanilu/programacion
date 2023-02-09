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
    const int MOD = 998244353;
    const char nl = '\n';
    const int MX = 100001;
    const int N=1000+3;

    void solve(){
        ll n;
        cin>>n;
        ll a[n];
        map<ll,ll> m;
        FOR(i,0,n){
            cin>>a[i];
            m[a[i]]++;
        }
        sort(a,a+n);
        ll ans=1,ctm=1,k=m[a[n-1]-1];
        FOR1(i,1,n){
            ans*=i;
            if(i!=k+1){
                ctm*=i;
                ctm%=MOD;
            }
            ans%=MOD;
        }
        if(m[a[n-1]]>=2){
            cout<<ans<<"\n";
        }
        else{
            cout<<(ans-ctm+MOD)%MOD<<"\n";
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








