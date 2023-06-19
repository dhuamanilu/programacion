#include <bits/stdc++.h>
using namespace std;
int main(){

    cout<<1<<"\n";
    cout<<2000<<"\n";
    vector<int> a;
    for(int i=0;i<2000;i++){
        a.push_back(i+1);
    }
    auto rng = std::default_random_engine {};
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());

    std::shuffle(std::begin(a), std::end(a), rng);
    for(int i=0;i<2000;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";

    return 0;
}








