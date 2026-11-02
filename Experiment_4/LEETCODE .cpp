class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
         // Adjacency list
        vector<vector<int>> adj(n + 1);
        
        // Indegree of every course
        vector<int> indegree(n + 1, 0);
        
        // Build graph
        for (auto relation : relations) {
            int u = relation[0];
            int v = relation[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        // earliest[i] = earliest time at which course i can be completed
        vector<int> earliest(n + 1, 0);
        
        queue<int> q;
        
        // Courses with no prerequisites
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                earliest[i] = time[i - 1];
            }
        }
        
        int answer = 0;
        
        // Topological sort
        while (!q.empty()) {
            
            int u = q.front();
            q.pop();
            
            answer = max(answer, earliest[u]);
            
            for (int v : adj[u]) {
                
                // Course v can start only after u is completed
                earliest[v] = max(earliest[v], earliest[u] + time[v - 1]);
                
                indegree[v]--;
                
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return answer;
    }
};
