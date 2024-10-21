/*
1679. Max Number of K-Sum Pairs



You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int num_ksums = 0;
        unordered_map<int, int> seen;
        for(int n: nums) {
            if (auto it = seen.find(k-n); it !=seen.end()) {
                num_ksums++;
                if (--it->second == 0) seen.erase(it);
            } else seen[n]++;
        }
        return num_ksums;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int maxOperations1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int num_ops = 0, l = 0, r = nums.size()-1;
        while(l < r) {
            int sum = nums[l] + nums[r];
            if (sum < k) l++;
            else if (sum > k) r--;
            else {
                num_ops++;
                l++; r--;
            }
        }
        return num_ops;
    }
    int maxOperations2(vector<int>& nums, int k) {
        unordered_map<int, int> ksum;
        int num_ops = 0;
        for(int n : nums) {
            int diff = k - n;
            if (ksum.find(diff) == ksum.end()) ksum[n]++;
            else {
                num_ops++;
                ksum[diff]--;
                if (ksum[diff] == 0) ksum.erase(diff);
            }
        }
        return num_ops;
    }
};