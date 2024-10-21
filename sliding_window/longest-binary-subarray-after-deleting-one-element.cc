/*
Code
Testcase
Test Result
Test Result
1493. Longest Subarray of 1's After Deleting One Element



Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, k = 1;
        while(r < nums.size()) {
            if (!nums[r++]) k--;
            if (k < 0 && !nums[l++]) k++;
        }
        return r - l - 1;
    }

    int longestSubarray1(vector<int>& nums) { 
        int seen0at = -1;
        int l = 0, r = 0, len = 0;
        while (l <= r && r < nums.size()) {
            if (!nums[r]) {
                if (seen0at >= l) {
                    int ones = r-l-1; len = max(len, ones);
                    l = seen0at + 1;
                    seen0at = r;
                }
                seen0at = r;
            }
            r++;
        }

        int ones = r-l;
        if (seen0at >= l || seen0at < 0) ones--;
        len = max(len, ones);
        return len;
    }
};