class Solution {
   public:
    void dfsSolve(int node, vector<int> adj[], int vis[], vector<int>& ans) {
        vis[node] = 1;
        ans.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsSolve(it, adj, vis, ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        int st = 0;
        vector<int> dfs;
        dfsSolve(st, adj, vis, dfs);
        return dfs;
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);

        vector<int> bfs;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            bfs.push_back(node);
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs;
    }
};
