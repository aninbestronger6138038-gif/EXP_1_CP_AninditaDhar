// expriment 3 
class Solution {
public:
    const long long MOD = 1e9 +7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int ,int>>>  adj(n);
        for(auto road : roads){
             int u = road[0];
             int v = road[1];
             int w = road[2];

             adj[u].push_back({v,w});
             adj[v].push_back({u,w});
        }

        priority_queue<pair<long long , int> , vector <pair<long long ,int>>, greater<pair<long long ,int>>> pq;

        vector<long long > distance(n, LLONG_MAX);

        vector <int> pathCount(n,0);

        pq.push({0,0});
        distance[0]=0;
        pathCount[0] =1;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            long long curr_dist = p.first;
            int currNode  = p.second;

            for(auto adjacent  : adj[currNode]){
                 int adjacent_node = adjacent.first;
                 int adj_dist = adjacent.second;

                 if(curr_dist + adj_dist < distance[adjacent_node] ){
                    distance[adjacent_node] = curr_dist + adj_dist ;
                    pq.push({curr_dist + adj_dist , adjacent_node});
                    pathCount[adjacent_node] = pathCount[currNode];
                 }
                 else if (curr_dist + adj_dist  == distance [adjacent_node]){
                         pathCount[adjacent_node] = (pathCount[adjacent_node] + pathCount[currNode]) % MOD;

                 }
            }
        }
      
        return pathCount[n-1];
    }
};
