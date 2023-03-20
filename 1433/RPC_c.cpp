#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    double n, k;
    double d, s;

    cin >> n >> k;
    cin >> d >> s;

    double res = ((d*n)-(k*s))/(n-k);

    string variables = to_string((int)(res));

    cout << setprecision(variables.size()+7);

    if(res > 100 || res < 0) {
        cout << "impossible";
    }else {
        cout << res;
    }
    return 0;
}








