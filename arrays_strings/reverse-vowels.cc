/**
 * 
 345. Reverse Vowels of a String


Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"

 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
 */

class Solution {
public:
    bool isvowel(char a) {
        a = tolower(a);
        //return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
        return "aeiou"s.find(a) != std::string::npos;
    }
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            if (!isvowel(s[l])) l++;
            else if (!isvowel(s[r])) r--;
            else swap(s[l++], s[r--]);
        }
        return s;
    }
};