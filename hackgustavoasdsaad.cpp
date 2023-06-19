#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("entrada.out","w",stdout);
    cout<<10000<<'\n';

    vector<pair<int,string>> a;
    for(int i=0;i<10000;i++){
        string aux="acdbegdbcfeagagfdfdcafegbcagdcdbafgebcadcbgadcbedcg";
        string aux2="";
        for(int j=0;j<50;j++){
            aux2+=aux[j%29];
        }
        a.push_back({50,aux2});
    }
    auto rng = std::default_random_engine {};
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());

    std::shuffle(std::begin(a), std::end(a), rng);
    for(int i=0;i<10000;i++){

        cout<<a[i].first<<'\n';
        if(i!=9999)
        cout<<a[i].second<<'\n';
        else
            cout<<a[i].second;
    }
    cout<<'\n';

    return 0;
}








