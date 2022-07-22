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
    ll n;
    cin>>n;
    ll a[n];

    FOR(i,0,n){
        cin>>a[i];
    }
    if(a[n-2]> a[n-1]){
        cout<<"-1\n";
        return;
    }
    else{
        bool ok=false;
        FOR(i,0,n-1){
            if(a[i]<=a[i+1]){
                ok=true;
            }
            else{
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<"0\n";
            return;
        }
        vector <pair<ll,pair<ll,ll>>> res;
        ll ope=0;
        FOR(i,0,n){
            int auxi=i+1;
            int guarda=auxi;
            if(a[i]<= a[auxi]) continue;
            else{
                guarda++;
                while(guarda < n && a[guarda]<0){
                    guarda++;
                }
                if(guarda == n-1 && a[guarda]<0){
                    cout<<"-1\n";
                    return;
                }
                a[i]=a[auxi]-a[guarda];
                ope++;
                pair<ll,ll> auxi2;
                auxi2.first=auxi;
                auxi2.second=guarda;
                pair <ll,pair<ll,ll>> auxi3;
                auxi3.first=i;
                auxi3.second=auxi2;
                res.emplace_back(auxi3);
            }
        }
        if(a[n-2] < a[n-3]){
            a[n-3]=a[n-2]-a[n-1];
            ope++;
            pair<ll,ll> auxi2;
            auxi2.first=n-2;
            auxi2.second=n-1;
            pair <ll,pair<ll,ll>> auxi3;
            auxi3.first=n-3;
            auxi3.second=auxi2;
            res.emplace_back(auxi3);
        }
        cout<<ope<<"\n";
        FOR(i,0,res.size()){
            cout<<res[i].first+1<<" "<<res[i].second.first+1<<" "<<res[i].second.second+1<<"\n";
        }

    }
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
