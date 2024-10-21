/*
399. Evaluate Division



You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
*/

class Solution {
public:
    void dfs(unordered_map<string, unordered_map<string, double>>& adj, 
                string src, double value, unordered_map<string, double>& visited) {
        visited[src] = value;
        for(auto& [n, v] : adj[src]) {
            if (visited.find(n) != visited.end()) continue;
            double nv = v * value;
            dfs(adj, n, nv, visited);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj{};
        for(int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].insert({equations[i][1], values[i]});
            adj[equations[i][1]].insert({equations[i][0], 1 / values[i]});
        }
        
        for(auto& [node, _] : adj) {
            unordered_map<string, double> visited{};
            dfs(adj, node, 1.0, visited);
            for(auto& [n, v]: visited) {
                if (adj[node].find(n) != adj[node].end()) continue;
                adj[node].insert({n, v});
                adj[n].insert({node, 1 /v});
            }
        }

        vector<double> res;
        for(auto& q : queries) {
            if (adj.find(q[0]) == adj.end() || adj[q[0]].find(q[1]) == adj[q[0]].end()) res.push_back(-1);
            else res.push_back(adj[q[0]][q[1]]);
        }
        return res;
    }
};