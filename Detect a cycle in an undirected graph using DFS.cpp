class Solution{
public:
    bool dfs(int node, int parent, int vis[], vector<int> adj[]){
        vis[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i, node, vis, adj)) return true;
            }
            else if(i != parent) return true;
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        return dfs(0, -1, vis, adj);
    }
};
