#include <bits/stdc++.h>
using namespace std;
int longest_increasing_subsequence(vector<int>& arr)
{
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
        if (it == ans.end()) {
            ans.push_back(arr[i]);
        }
        else {
            *it = arr[i];
        }
    }
    return ans.size();
}
int main()
{
    vector<int> a = { 10, 22, 9, 33, 21, 50, 41, 60,10,11,12,13,14,15,16,17 };
    int ans = longest_increasing_subsequence(a);
    cout << ans;
    return 0;
}
