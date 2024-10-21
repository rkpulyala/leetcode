/*
649. Dota2 Senate

Medium
Topics
Companies
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

 

Example 1:

Input: senate = "RD"
Output: "Radiant"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
Example 2:

Input: senate = "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
 

Constraints:

n == senate.length
1 <= n <= 104
senate[i] is either 'R' or 'D'.
*/

class Solution {
public:
    string predictPartyVictory(string senate) {
        std::queue<int> r, d;
        for(int i = 0; i < senate.size(); i++) senate[i] == 'R' ? r.push(i) : d.push(i);
        int sz = senate.size();

        while(!r.empty() && !d.empty()) {
            int rf = r.front(), df = d.front();
            if (rf < df) { 
                d.pop(); // ban D
                r.pop(); r.push(rf + sz); // rotate R
            } else { 
                r.pop(); // ban R
                d.pop(); d.push(df + sz); // rotate D
            }
        }
        if (r.empty()) return "Dire";
        return "Radiant";
    }

    int next_position(int n1, int n2, int p) {
        if (n1 == p || n2 == p) return p;
        if ((p < n1 && p < n2) || (p > n1 && p > n2)) return min(n1, n2);
        if (p < n1) return n1;
        return n2;
    }
    string predictPartyVictory2(string senate) {
        std::queue<int> r, d;
        for(int i = 0; i < senate.size(); i++) senate[i] == 'R' ? r.push(i) : d.push(i);
        int p = 0, sz = senate.size();

        while(!r.empty() && !d.empty()) {
            if (r.front() == p) { 
                r.push(r.front()); r.pop(); // rotate
                d.pop(); // ban D
            }
            else if (d.front() == p) { 
                d.push(d.front()); d.pop(); // rotate
                r.pop(); // ban R
            }
            p = next_position(r.front(), d.front(), (p+1) % sz);
        }
        if (r.empty()) return "Dire";
        return "Radiant";
    }

    string predictPartyVictory1(string senate) {
        std::queue<int> r, d;
        for(int i = 0; i < senate.size(); i++) senate[i] == 'R' ? r.push(i) : d.push(i);
        int p = 0, sz = senate.size();

        while(!r.empty() && !d.empty()) {
            if (r.front() == p) { 
                r.push(r.front()); r.pop(); // rotate
                d.pop(); // ban D
            }
            else if (d.front() == p) { 
                d.push(d.front()); d.pop(); // rotate
                r.pop(); // ban R
            }
            p = (p+1) % sz;
        }
        if (r.empty()) return "Dire";
        return "Radiant";
    }
};