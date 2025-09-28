#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int>& nums, int x) {
        int n = nums.size();
        int floor = -1, ceil = -1;

        // Binary search for floor
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= x) {
                floor = nums[mid];
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Reset start and end for ceil
        start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= x) {
                ceil = nums[mid];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return {floor, ceil};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 4, 7, 8, 10};

    int x;
    cout << "Enter x: ";
    cin >> x;

    vector<int> result = sol.getFloorAndCeil(nums, x);
    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;

    return 0;
}
