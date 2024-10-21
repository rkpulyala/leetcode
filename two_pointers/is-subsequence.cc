/*
392. Is Subsequence


Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, set<int>> mp;
        for(int i = 0; i < t.size(); i++) mp[t[i]].insert(i);
        int last_index = -1;
        for(int i = 0; i < s.size(); i++) {
            if (auto it = mp.find(s[i]); it != mp.end()) {
                auto vs = it->second;
                auto ind_it = vs.upper_bound(last_index);
                if(ind_it == vs.end()) return false;
                last_index = *ind_it;
            } else return false;
        }
        return true;
    }
    bool isSubsequence2(string s, string t) {
        int i = 0;
        if (s.empty()) return true;
        if (s.size() > t.size()) return false;
        for(char c: t) {
            if (c == s[i]) {
                i++;
                if (i == s.size()) return true; 
            }
        }
        return false;
    }
    bool isSubsequence1(string s, string t) {
        int i = 0;
        for(char c: t) {
            if (i == s.size()) return true;
            if (s[i] == c) i++;
        }
        return i == s.size();
    }
};