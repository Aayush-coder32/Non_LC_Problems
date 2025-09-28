#include <iostream>
using namespace std;

class Solution {
public:
    int NthRoot(int N, int M) {
        int start = 1, end = M;

        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long power = 1;
            for (int i = 0; i < N; ++i) {
                power *= mid;
                if (power > M) break; // Early stop if power exceeds M
            }

            if (power == M) return mid;
            else if (power < M) start = mid + 1;
            else end = mid - 1;
        }

        return -1;
    }
};
int main() {
    Solution sol;

    int N1 = 3, M1 = 27;
    cout << "Input: N = " << N1 << ", M = " << M1 << endl;
    cout << "Output: " << sol.NthRoot(N1, M1) << endl; // 3

    int N2 = 4, M2 = 69;
    cout << "Input: N = " << N2 << ", M = " << M2 << endl;
    cout << "Output: " << sol.NthRoot(N2, M2) << endl; // -1

    return 0;
}
