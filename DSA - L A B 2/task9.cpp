#include <iostream>
#include <vector>
#include<algorithem>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total_sum = 0;
        int curr_sum1 = 0;
        int curr_sum2 = 0;
        int max_subarray_sum = INT_MIN;
        int min_subarray_sum = INT_MAX;

        for (int i = 0; i < A.size(); i++) {
            int num = A[i];
            total_sum += num;
            curr_sum1 += num;
            curr_sum2 += num;

            max_subarray_sum = max(max_subarray_sum, curr_sum1);
            if (curr_sum1 < 0) {
                curr_sum1 = 0;
            }

            min_subarray_sum = min(curr_sum2, min_subarray_sum);
            if (curr_sum2 > 0) {
                curr_sum2 = 0;
            }
        }

        
        if (total_sum == min_subarray_sum) {
            return max_subarray_sum;
        } else {
            return max(max_subarray_sum, total_sum - min_subarray_sum);
        }
    }
};

int main() {
    Solution solution;
    vector<int> A = {1, -2, 3, -2};
    int maxCircularSum = solution.maxSubarraySumCircular(A);
    cout << "Maximum Circular Subarray Sum: " << maxCircularSum << endl;

    return 0;
}
