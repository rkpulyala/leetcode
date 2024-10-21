/**
 * https://github.com/rkpulyala/leetcode.git
 
1768. Merge Strings Alternately



You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
 */

#include <string>
using std::string;

class Solution {
public:
    string mergeAlternately1(string word1, string word2) {
        string out;
        for(int i = 0; i < word1.size() && i < word2.size(); i++) {
            out.push_back(word1[i]);
            out.push_back(word2[i]);
        }
        for(int i = word2.size(); i < word1.size() ; i++) {
            out.push_back(word1[i]);
        }
        for(int i = word1.size(); i < word2.size() ; i++) {
            out.push_back(word2[i]);
        }
        return out;
    }
    string mergeAlternately(string word1, string word2) {
        string out;
        int len1 = word1.length();
        int len2 = word2.length();
        int min_len = std::min(len1, len2);
        for(int i = 0; i < min_len; i++) {
            out.push_back(word1[i]);
            out.push_back(word2[i]);
        }
        string& longer = len1 > len2? word1 : word2;
        for(int i = min_len; i < longer.length(); i++) out.push_back(longer[i]);
        return out;
    }
};