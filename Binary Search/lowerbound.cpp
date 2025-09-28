// Given a sorted array of nums and an integer x, write a program to find the lower bound of x. 
// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
// If no such index is found, return the size of the array.

// Examples:
// Input : nums= [1,2,2,3], x = 2

// Output:1

// Explanation: Index 1 is the smallest index such that arr[1] >= x.

// Input : nums= [3,5,8,15,19], x = 9

// Output: 3

// Explanation: Index 3 is the smallest index such that arr[3] >= x.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int> &nums, int x) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = nums.size(); 

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] >= x) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 3, 5, 6, 8, 10};

    int x;
    cout << "Enter the number to find lower bound of: ";
    cin >> x;

    int index = sol.lowerBound(nums, x);

    if (index == nums.size()) {
        cout << "No element >= " << x << " found in the array." << endl;
    } else {
        cout << "Lower bound of " << x << " is at index " << index << " (value = " << nums[index] << ")." << endl;
    }

    return 0;
}
