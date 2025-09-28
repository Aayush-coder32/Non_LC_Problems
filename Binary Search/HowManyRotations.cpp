//In a right-rotated sorted array, the smallest element will be the rotation pivot.
//For example, in [4, 5, 6, 7, 0, 1, 2, 3], the smallest element is 0 at index 4, 
//meaning the array has been rotated 4 times.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findRotationCount(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }

        return start;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << "Rotations for [4, 5, 6, 7, 0, 1, 2, 3]: "
         << sol.findRotationCount(nums1) << endl;

    vector<int> nums2 = {3, 4, 5, 1, 2};
    cout << "Rotations for [3, 4, 5, 1, 2]: "
         << sol.findRotationCount(nums2) << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Rotations for [1, 2, 3, 4, 5]: "
         << sol.findRotationCount(nums3) << endl;

    return 0;
}
