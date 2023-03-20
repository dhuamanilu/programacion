#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using ld = long double;
const ld PI = 3.14159265359;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ld a;
    cin >> a;
    ld l=2*PI*sqrt(a/PI);
    cout<< setprecision(20) << l << endl;
    return 0;
}
