class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Adjacency list
        vector<vector<int>> adj(numCourses);
        
        // Indegree of each course
        vector<int> indegree(numCourses, 0);
        
        // Build graph
        for (auto p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];
            
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        
        // Queue for courses with no prerequisites
        queue<int> q;
        
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        
        // Topological Sort
        while (!q.empty()) {
            
            int u = q.front();
            q.pop();
            
            count++;
            
            for (int v : adj[u]) {
                
                indegree[v]--;
                
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // If all courses are processed, there is no cycle
        return count == numCourses;
    }
};
