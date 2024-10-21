/**
 * 
 2352. Equal Row and Column Pairs



Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

Example 1:


Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
Example 2:


Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105
 */

class Solution {
public:
    string vec_to_string(vector<int>& v) {
        string s;
        for (int i:v) s.append(to_string(i)+',');
        return s;
    }
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rows;
        int n = grid.size();
        for (auto& v: grid) {
            string s = vec_to_string(v);
            rows[s]++;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) v.push_back(grid[j][i]);
            if (auto it = rows.find(vec_to_string(v)); it != rows.end())
                count += it->second;
        }
        
        return count;
    }
    /**int equalPairs(vector<vector<int>>& grid) {
        unordered_map<vector<int>, int> rows;
        int n = grid.size();
        for (auto& v: grid) rows[v]++;
        int count = 0;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) 
                v.push_back(grid[j][i]);
            if (auto it = rows.find(v); it != rows.end())
                count += it->second;
        }
        return count;
    }*/
    
    int equalPairs2(vector<vector<int>>& grid) {
        unordered_map<string, int> rs, cs;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            string r, c;
            for (int j = 0; j < n; j++) {
                r.append(to_string(grid[i][j])+',');
                c.append(to_string(grid[j][i])+',');
            }
            rs[r]++;
            cs[c]++;
        }
        int count = 0;
        for(auto& [k, v]: rs) {
            if (auto it = cs.find(k); it != cs.end()) {
                count += v * it->second;
            }
        }
        return count;
    }
    int equalPairs1(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> rowSums, colSums;
        for (int i = 0; i < n; i++) {
            int rs = 0, cs = 0;
            for (int j = 0; j < n; j++) {
                rs += grid[i][j];
                cs += grid[j][i];
            }
            rowSums[rs].push_back(i);
            colSums[cs].push_back(i);
        }
        int count = 0;
        for(auto& [sum, rows]: rowSums) {
            if (auto it = colSums.find(sum); it != colSums.end()) {
                auto& [_, cols] = *it;
                for(int i: rows) {
                    for (int j: cols) {
                        bool eq = true;
                        for(int k = 0; k < n; k++) {
                            if(grid[i][k] != grid[k][j]) { eq = false; break; } 
                        }
                        if (eq) count++;
                    }
                }
            }
        }
        return count; 
    }
};