#include <iostream>
#include <cmath>
#include <string>

std::string find_minimum_string(int n) {
    std::string s;
    int k = static_cast<int>(std::sqrt(n));

    for (int i = 0; i < k; i++) {
        s += char('a' + i);
    }

    if (s.length() < n) {
        s += s.substr(0, n - s.length());
    }

    return s;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string result = find_minimum_string(n);
        std::cout << result << std::endl;
    }

    return 0;
}
