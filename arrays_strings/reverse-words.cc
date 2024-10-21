/**
 151. Reverse Words in a String

Medium
Topics
Companies
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
 */

class Solution {
public:
    string reverseWords(string s) {
        int i = s.size()-1, j = i;
        string out;
        while(i >= 0) {
            j = s.rfind(' ', i);
            if (j == i) i--;
            else {
                if (!out.empty()) out.push_back(' ');
                out.append(s.substr(j+1, i-j));
                i = j-1;
            }
        }
        return out;
    }


    string reverseWords3(string s) {
        int i = s.size()-1, j = i;
        string out;
        while(i >= 0 && j >= 0) {
            while(i >= 0 && s[i] == ' ') i--;
            int j = i;
            while(j >= 0 && s[j] != ' ') j--;
            out.append(s.substr(j+1, i-j));
            i = j-1;
            if (i>=0) out.push_back(' ');
        }
        while(out.back() == ' ') out.pop_back();
        return out;
    }

    void reverse(string& s) { std::reverse(s.begin(), s.end()); }
    string reverseWords2(string s) {
        reverse(s);
        while(s.back() == ' ') s.pop_back();
        string out;
        size_t i = 0;
        while(i < s.size()) {
            size_t delimit = s.find(' ', i); 
            if (delimit == i) i++; 
            else if (delimit != std::string::npos) {
                string subs = s.substr(i, delimit-i);
                reverse(subs);
                out.append(subs); out.push_back(' ');
                i = delimit+1;
            } else break;
            
        }
        string subs = s.substr(i, s.size()); reverse(subs);
        out.append(subs);
        return out;
    }

    void reverse(string& s, int l, int r) {
        while(l < r) {
            std::swap(s[l], s[r]);
            l++; r--;
        }
    }
    string reverseWords1(string s) {
        int l = 0, last = s.size()-1;
        reverse(s, 0, last);
        string out;
        while(l <= last) {
            while(l <= last && s[l] == ' ') l++;
            string word;
            while(l <= last && s[l] != ' ') { word.push_back(s[l]); l++; } 
            if (word.size() > 0) {
                reverse(word, 0, word.size()-1);
                for(char c: word) out.push_back(c);
                out.push_back(' ');
            }
        }
        if (out.back() == ' ') out.pop_back();
        return out;
    }
};