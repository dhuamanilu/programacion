#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin>>n;
    vector<ll> a(n/2),b(n/2);
    for(auto & e : a){
        cin>>e;
        e--;
    }
    for(auto & e : b){
        cin>>e;
        e--;
    }
    vector<ll> p(n,1);
    auto bina=[&](ll tar){
        ll s=0,e=n-1,m=s+(e-s)/2;
        while(s<=e){
            m=s+(e-s)/2;
            
        }
    };
    return 0;
}
