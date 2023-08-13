#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll funcionMotona(ll m,ll k,ll t){
    ll ans=0,var=k;
    ans+=m;
    while(m/var>0){
        ans+=m/var;
        var*=k;
    }
    return ans;
}

ll bs(ll lo,ll hi, ll t,ll k){
    while(lo<hi){
        ll m = (lo+hi)/2;
        ll abc=funcionMotona(m,k,t);
        if(t<=abc)hi=m-1;
        else lo=m+1;
    }
    return lo;
}

int main(){
    ll n,k;
    cin>>n>>k;
    cout<<bs(0,(ll)1e17,n,k);
}








