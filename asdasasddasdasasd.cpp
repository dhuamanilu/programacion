#include <iostream>
#include <climits> // for INT_MAX

using namespace std;

int main() {
    // Read in the number of test cases
    int t;
    cin >> t;

    // Loop through each test case
    while (t--) {
        // Read in the size of the array and the index of Baltic's favorite number
        int n, m;
        cin >> n >> m;

        // Read in the array
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Initialize the minimum prefix sum seen so far and the number of operations
        int min_prefix_sum = INT_MAX;
        int num_operations = 0;

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Update the prefix sum
            min_prefix_sum += a[i];

            // If the prefix sum is less than the minimum prefix sum seen so far,
            // update the minimum prefix sum and increment the number of operations
            if (min_prefix_sum < 0 && i >= m - 1) {
                min_prefix_sum = -min_prefix_sum;
                num_operations++;
            }
        }

        // Print the number of operations
        cout << num_operations << endl;
    }

    return 0;
}
