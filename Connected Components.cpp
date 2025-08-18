class Solution {
    vector<vector<int>> adj;

   public:
    void dfs(int i, vector<bool> &vis) {
        vis[i] = true;
        for (auto j : adj[i])
            if (!vis[j]) dfs(j, vis);
    }
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        vector<bool> vis(V, 0);
        adj.resize(V);

        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int ans(0);
        for (int i(0); i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis); ans++;
            }
        }

        return ans;
    }
};
