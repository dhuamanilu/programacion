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
    ll n,q;
    cin>>n>>q;
    vector <pair<ll,ll>> rect(n);
    FOR(i,0,n){
        ll d,e;
        cin>>d>>e;
        rect[i]=mp(d,e);
    }
    sort(all(rect));
    vector <ll> areas(n);
    areas[0]=rect[0].first*rect[0].second;
    FOR(i,1,n){
        areas[i]=areas[i-1]+ rect[i].first*rect[i].second;
    }

    FOR(l,0,q){
        ll h1,w1,h2,w2;
        cin>>h1>>w1>>h2>>w2;
        ll cont=0;
        ll ind=-1;
        FOR(i,0,n){
            if(rect[i].first>h1 && rect[i].second>w1){
                ind=i;
                break;
            }
        }
        ll ind2=-1;
        FOR(i,0,n){
            if(rect[i].first<h2
               && rect[i].second<w2){
                ind2=i;
            }
            else{
                break;
            }
        }
        if(ind2==0){
            cout<<areas[ind-1]<<"\n";
            continue;
        }
        if(ind==0){
           cout<<areas[ind2]<<"\n";
           continue;
        }
        if(ind2==-1){
            cout<<"0\n";
            continue;
        }

        else if(ind ==-1)
            cont=0;
        else if(ind>ind2){
            ind=0;
        }
        else
            cont=areas[ind2]-areas[ind-1];

        //cout<<"aasdasdasasdas : "<<ind2<<" "<<ind-1<<" "<<areas[ind2]<<" "<<areas[ind-1]<<"\n";
        cout<<cont<<"\n";
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








