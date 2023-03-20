#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    map<string ,long long>lef,ri,an;
    set<string> names;
    for(long long i=0;i<n;i++){
        string a,b;
        cin>>a;
        cin>>b;
        names.insert(a);
        long long k;
        cin>>k;

        if(b=="left"){
            lef[a]+=k;
        }
        else if(b=="right"){
            ri[a]+=k;
        }
        else{
            an[a]+=k;
        }
    }
    long long ans=0,peligro=0;

    for(auto e : names){
        long long a1=0,a2=0,a3=0;
        auto b1=lef.count(e),b2=ri.count(e),b3=an.count(e);
        if(b1){
            a1=lef[e];
        }
        if(b2){
            a2=ri[e];
        }
        if(b3){
            a3=1;
        }
        if( (b1 && !b2 && !b3)
           || (b2 && !b1 && !b3 ) || (!b1 && !b2 && (b3 && an[e]==1))
           ){
            peligro++;
        }

        long long su=max(a1,max(a2,a3));
        ans+=su;
    }
    if(peligro==(long long)names.size()){
        cout<<"impossible"<<endl;
    }
    else{
        cout<<ans+1<<endl;
    }

    return 0;
}
