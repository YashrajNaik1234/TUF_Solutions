class Solution{
public:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto i : adj[node]){
            if(!vis[i] and dfs(i, adj, vis, pathVis)) return true;
            else if(pathVis[i]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int N, vector<int> adj[]) {
        int vis[N] = {0};
        int pathVis[N] = {0};
        
        for(int i(0);i < N;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)) return true;
            }
        }
        
        return false;
    }
};
