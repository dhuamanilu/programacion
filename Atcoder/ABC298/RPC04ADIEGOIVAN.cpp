#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <string>

using ll = long long;
using ld = long double;
using namespace std;

int main() {
    ll n, k, x;
    cin >> n >> k >> x;
    double average = 0;
    ll arr[n];
    for(ll i=0; i<n; i++) {
        cin >> arr[i];
        average += arr[i];
    }
    average /= n;
    ll aux = n;
    double proms[k];
    double min = INT_MAX;

    if(x > average) {

        for(ll i=0; i<k; i++) {
            average -= (double)(arr[i])/aux;
            average = (double)(average*aux)/(aux-1);
            if(abs(x-average) < min) {
                min = abs(x-average);
            }
            aux--;
        }

    }else {

        for(ll i=n-1; i>n-k-1; i--) {
            average -= (double)(arr[i])/aux;
            average = (double)(average*aux)/(aux-1);
            if(abs(x-average) < min) {
                min = abs(x-average);
            }
            aux--;
        }

    }

    min = round(min*100000)/100000;

    cout << min;
    return 0;
}
