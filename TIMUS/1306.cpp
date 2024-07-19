
#include <iostream>
#include <iomanip> // Para std::fixed y std::setprecision
#include <algorithm> // Para std::sort
void solve() {
	int n;
    std::cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    std::sort(a,a+n);
    if(n%2==0){
        std::cout<<std::fixed<<std::setprecision(1)<<(double)(1.0*a[n/2] + a[(n/2) - 1])/2;
    }
    else{
        std::cout<<std::fixed<<std::setprecision(1)<<(a[n/2]);
    }
   
}
int main() {
    solve();
}








