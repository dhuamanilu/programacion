#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

unordered_map<long long, double> memo;

double min_cost(long long N, long long A, long long X, long long Y) {
    if (N == 0) return 0;
    if (memo.find(N) != memo.end()) return memo[N];
    
    double expected_cost = X + min_cost(N / A, A, X, Y); // Pay X to replace N with floor(N/A)
    int num_divisible = 0;
    
    for (int j = 2; j <= 6; j++) {
        if (N % j == 0) {
            expected_cost += (1.0 / 6) * (Y + min_cost(N / j, A, X, Y)); // Pay Y to roll a die and replace N with floor(N/b)
            num_divisible++;
        } else {
            long long k = N / j;
            expected_cost += (1.0 / 6) * (Y + (j - 1) * X + min_cost(k, A, X, Y)); // Pay Y to roll a die and also pay X for each additional operation
        }
    }
    
    if (num_divisible == 0) {
        memo[N] = expected_cost;
        return expected_cost;
    }
    
    // Adjust expected cost to account for the case where N is divisible by the dice outcome
    expected_cost /= (1 - (1.0 / 6) * num_divisible);
    memo[N] = expected_cost;
    return expected_cost;
}

int main() {
    long long N, A, X, Y;
    cin >> N >> A >> X >> Y;
    
    double result = min_cost(N, A, X, Y);
    cout << result << endl;
    
    return 0;
}