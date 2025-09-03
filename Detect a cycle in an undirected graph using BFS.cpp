class Solution{
public:
    bool detect(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto i:adj[x]){
                if(!vis[i]){
                    vis[i] = 1; q.push({i, x});
                }
                else if(y != i) return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i(0);i < V;i++){
            if(!vis[i]){
                if(detect(i, adj, vis)) return true;
            }
        }
        
        return false;
    }
};
