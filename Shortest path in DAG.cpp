class Solution {
    public:
    void toposort(int i, vector<pair<int, int>> adj[], int vis[],
                  stack<int>& st) {
        vis[i] = 1;
        for (auto it : adj[i]) {
            if (!vis[it.first]) toposort(it.first, adj, vis, st);
        }
        st.push(i);
    }
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        vector<pair<int, int>> adj[N];
        for (int i(0); i < M; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        int vis[N] = {0};
        stack<int> st;
        for (int i(0); i < N; i++) {
            if (!vis[i]) toposort(i, adj, vis, st);
        }

        vector<int> dist(N, -1);
        dist[0] = 0;
        while(!st.empty()){
            if(st.top() != 0) st.pop();
            else break;
        }
        while(!st.empty()){
            int node = st.top(); st.pop();
            for(auto it:adj[node]){
                int v = it.first;
                int wt = it.second;

                if(dist[node] + wt < dist[v]) dist[v] = dist[node] + wt;
            }
        }

        return dist;
    }
};

