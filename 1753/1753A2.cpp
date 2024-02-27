#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
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
    ll a[n];
    ll pos=0,neg=0;
    FOR(i,0,n){
        cin>>a[i];
        if(a[i]>0) pos++;
        else if(a[i]<0) neg++;
    }
    if((pos+neg)%2==1){
    	cout<<"-1\n";
    }
    else{
    	if(pos>neg){
    		ll cua=(pos-neg)/2;
    		vpll ans;
    		bool disp=true;
    		FOR(i,0,n){
    			if(a[i]<=0 || cua<=0){
    				ans.pb(mp(i,i));
    				disp=true;
    			}
    			else{
    				if(ans.size()>0 && disp){
    					disp=false;
    					auto x=ans.back();
    					ans.pop_back();
    					ans.pb(mp(x.f,i));
    					cua--;
    				}
    				else{
    					ans.pb(mp(i,i));
    					disp=true;
    				}
    				
    			}
    		}
    		cout<<ans.size()<<"\n";
    		for(auto & e : ans){
    			cout<<e.f+1<<" "<<e.se+1<<"\n";
    		}
    	}
    	else{
    		ll cua=(neg-pos)/2;
    		vpll ans;
    		bool disp=true;
    		FOR(i,0,n){
    			if(a[i]>=0 || cua<=0){
    				ans.pb(mp(i,i));
    				disp=true;
    			}
    			else{
    				if(ans.size()>0 && disp){
    					disp=false;
    					auto x=ans.back();
    					ans.pop_back();
    					ans.pb(mp(x.f,i));
    					cua--;
    				}
    				else{
    					ans.pb(mp(i,i));
    					disp=true;
    				}
    				
    			}
    		}
    		cout<<ans.size()<<"\n";
    		for(auto & e : ans){
    			cout<<e.f+1<<" "<<e.se+1<<"\n";
    		}
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








