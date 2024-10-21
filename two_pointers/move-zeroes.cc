/*
283. Move Zeroes



Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i]) nums[j++] = nums[i];
        }
        while(j < nums.size()) nums[j++] = 0;
    }

    void moveZeroes1(vector<int>& nums) {
        int zero_index = -1;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {zero_index = i; break; }
        }
        if (zero_index == -1) return;
        for(int i = zero_index+1; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            nums[zero_index++] = nums[i];
        }
        for(int i = zero_index; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};