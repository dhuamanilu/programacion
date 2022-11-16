#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (long long i=a; i<(b); i++)

using namespace std;
void solve(){
    ll n,m;
    cin>>n>>m;
    char a[n+5][m+5];
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>a[i][j];
        }
    }
    FOR(j,0,m){
        ll last=n-1;
        for(ll i=n-1;i>=0;i--){
            if(a[i][j]=='o'){
                last=i-1;
            }
            else{
                if(a[i][j]=='*'){
                    swap(a[i][j],a[last--][j]);
                }
            }
        }
    }
    FOR(i,0,n){
        FOR(j,0,m){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int main(){
        ios_base::sync_with_stdio(0);

    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}