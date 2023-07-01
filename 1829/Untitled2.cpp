#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        vector<pair<int, int>> sortedArray(n); // A pair to store element and its index
        for(int i=0; i<n; i++){
            sortedArray[i] = {a[i], i};
        }
        sort(sortedArray.begin(), sortedArray.end()); // Sort the array based on elements
        vector<int> left(n), right(n); // Store how far the element can go in left and right
        left[sortedArray[0].second] = sortedArray[0].second; // First element can go upto itself
        for(int i=1; i<n; i++){
            left[sortedArray[i].second] = min(left[sortedArray[i-1].second], sortedArray[i].second);
            // The farthest the element can go in left direction is the farthest element in left direction or itself
        }
        right[sortedArray[n-1].second] = sortedArray[n-1].second; // Last element can go upto itself
        for(int i=n-2; i>=0; i--){
            right[sortedArray[i].second] = max(right[sortedArray[i+1].second], sortedArray[i].second);
            // The farthest the element can go in right direction is the farthest element in right direction or itself
        }
        ll ans = 0;
        for(int i=0; i<n; i++){
            ans += (right[i]-i+1) * (i-left[i]+1) * a[i]; // Sum of the beauty of all subarrays
        }
        cout << ans << endl;
    }
    return 0;
}

