/*
994. Rotting Oranges
Solved
Medium
Topics
Companies
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
 */


class Solution {
public:
    vector<pair<int, int>> getNeighbors(vector<vector<int>>& grid, pair<int, int>& p) {
        vector<pair<int, int>> neighbors;
        auto [r,c] = p;
        if (r-1 >= 0 && grid[r-1][c] == 1) neighbors.push_back({r-1, c});
        if (r+1 < grid.size() && grid[r+1][c] == 1) neighbors.push_back({r+1, c});
        if (c-1 >= 0 && grid[r][c-1] == 1) neighbors.push_back({r, c-1});
        if (c+1 < grid[0].size() && grid[r][c+1] == 1) neighbors.push_back({r, c+1});
        return neighbors;
    }
    vector<pair<int, int>> rottenAtStart(vector<vector<int>>& grid) {
        vector<pair<int, int>>  at_start;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) at_start.push_back({i,j});
            }
        }
        return at_start;
    }
    vector<pair<int, int>> freshAtEnd(vector<vector<int>>& grid) {
        vector<pair<int, int>>  at_start;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) at_start.push_back({i,j});
            }
        }
        return at_start;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        auto rotten_at_start = rottenAtStart(grid);
        for(auto ras: rotten_at_start) q.push({ras, 0});
        int max_mins = 0;

        while(!q.empty()) {
            auto [rotten, mins] = q.front(); q.pop();
            vector<pair<int, int>> neighbors = getNeighbors(grid, rotten);
            for(auto p: neighbors) {
                grid[p.first][p.second] = 2;
                q.push({p, mins+1});
                max_mins = mins+1;
            }
        }
        auto fresh_at_end = freshAtEnd(grid);
        return fresh_at_end.empty()? max_mins : -1;
    }
};