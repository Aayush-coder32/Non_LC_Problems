#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if cows can be placed with at least 'minDist' distance apart
bool canPlaceCows(const vector<int>& stalls, int k, int minDist) {
    int count = 1; // Place the first cow at the first stall
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= minDist) {
            count++;
            lastPosition = stalls[i];
            if (count == k)
                return true;
        }
    }

    return false;
}

// Function to find the maximum possible minimum distance
int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int low = 1; // Minimum possible distance
    int high = stalls.back() - stalls.front(); // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, k, mid)) {
            result = mid;      // Update result and try for a bigger distance
            low = mid + 1;
        } else {
            high = mid - 1;    // Try smaller distance
        }
    }

    return result;
}

int main() {
    // Example 1
    vector<int> stalls1 = {0, 3, 4, 7, 10, 9};
    int k1 = 4;
    cout << "Maximum possible minimum distance: " << aggressiveCows(stalls1, k1) << endl;

    // Example 2
    vector<int> stalls2 = {4, 2, 1, 3, 6};
    int k2 = 2;
    cout << "Maximum possible minimum distance: " << aggressiveCows(stalls2, k2) << endl;

    return 0;
}
