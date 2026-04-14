#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 1: Find maximum value
    int maxVal = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Step 2: Create and initialize count array
    int count[maxVal + 1];
    for(int i = 0; i <= maxVal; i++) {
        count[i] = 0;
    }

    // Step 3: Store frequency
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 4: Prefix sum (cumulative count)
    for(int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Output array
    int output[n];

    // Step 6: Place elements in correct position (simple version)
    for(int i = n - 1; i >= 0; i--) {
        int value = arr[i];
        int position = count[value] - 1;

        output[position] = value;
        count[value]--;
    }

    // Step 7: Copy back to original array
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Step 8: Print sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

