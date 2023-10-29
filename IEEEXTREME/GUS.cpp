#include <cmath>
#include <iostream>

using namespace std;

// Calculates the cosine of an angle in radians.
double cos(double angle) {
  return std::cos(angle*PI/180);
}

// Finds the smallest positive integer n such that cos(na) is minimal.
int find(double angle) {
  int n = 1;
  double cos_na = cos(angle);

  // Iterate until we find the smallest n such that cos(na) is minimal.
  while (cos_na >= 0) {
    n++;
    cos_na = cos(n * angle);
  }

  return n;
}
void solve(){
    double angle;
  cin >> angle;
  cout<<find(angle)<<"\n";
}
int main() {
    long long test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}
