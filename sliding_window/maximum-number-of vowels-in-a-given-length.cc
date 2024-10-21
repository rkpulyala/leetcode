/*
1456. Maximum Number of Vowels in a Substring of Given Length



Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
*/

class Solution {
public:
    bool is_vowel(char ch) {
        //ch = std::tolower(ch); // Make it case-insensitive
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int max_vowels = 0;
        for(int i = 0; i < k; i++) if (is_vowel(s[i])) max_vowels++;
        for(int i = k, vowels = max_vowels; i < s.size() && max_vowels < k; i++) {
            if (is_vowel(s[i])) vowels++;
            if (is_vowel(s[i-k])) vowels--;
            max_vowels = max(max_vowels, vowels);
        }
        return max_vowels;
    }
};