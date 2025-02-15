/*
643. Maximum Average Subarray I


You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum = 0;
        for(int i = 0; i < k; i++) max_sum += nums[i];
        for(int i = k, sum = max_sum; i < nums.size(); i++) {
            sum += nums[i] - nums[i-k];
            max_sum = max_sum > sum? max_sum : sum;
        }
        return (double)max_sum/k;
    }
};