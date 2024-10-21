/**
 * 
 1071. Greatest Common Divisor of Strings



For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
 */

#include <string>
using std::string;

class Solution {
public:
    int mygcd(int a, int b) {
        while(a != 0) {
            int temp = a;
            a = b % a;
            b = temp;
        }
        return b;
    }
    int mygcd_r(int a, int b) {
        if (!a) return b;
        return mygcd_r(b%a, a);
    }
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int gcd = mygcd_r(str1.length(), str2.length());
        //int gcd = std::gcd(str1.length(), str2.length());
        //int gcd = mygcd(str1.length(), str2.length());
        return str1.substr(0, gcd);
    }
};