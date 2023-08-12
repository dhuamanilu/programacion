#include<bits/stdc++.h>
using namespace std;

int funcionMotona(int x){
    return x*x;
}

int bs(int lo, int hi, int t){
    while(lo<hi){
        int m = (lo+hi)/2;
        if(t==funcionMotona(m)) return m;
        if(t<funcionMotona(m))hi=m-1;
        else lo=m+1;
    }
    return lo;
}

int main(){
    int x;
    cin>>x;
    cout<<bs(0,x,x);
}
