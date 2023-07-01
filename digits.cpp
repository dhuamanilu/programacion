#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> allowedSet; // Allowed digits

bool isSpecialNumber(int num) {
    vector<bool> visited(10, false);

    while (num > 0) {
        int digit = num % 10;

        if (visited[digit])
            return false;

        visited[digit] = true;
        num /= 10;
    }

    return true;
}

int findSmallestSpecialNumber(int num, int digitCount) {
    if (digitCount > 9)
        return -1; // Invalid case, as we can't have more than 9 digits

    vector<int> digits;

    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }

    reverse(digits.begin(), digits.end());

    do {
        int specialNum = 0;
        int pow10 = 1;

        for (int i = 0; i < digitCount; i++) {
            specialNum += digits[i] * pow10;
            pow10 *= 10;
        }

        if (specialNum > num && isSpecialNumber(specialNum))
            return specialNum;
    } while (next_permutation(digits.begin(), digits.end()));

    return -1; // No special number found
}

int main() {
    ll N;
    cin >> N;

    for (int i = 0; i < 10; i++) {
        int digit;
        cin >> digit;
        allowedSet.push_back(digit);
    }

    int result = -1;

    // Try to find a special number with the same number of digits as N
    result = findSmallestSpecialNumber(N, to_string(N).length());

    if (result == -1) {
        // No special number found, try with an additional digit
        result = findSmallestSpecialNumber(N, to_string(N).length() + 1);
    }

    if (result == -1)
        cout << "O" << endl;
    else
        cout << result << endl;

    return 0;
}
