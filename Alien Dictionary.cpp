class Solution {
public:
    void dfs(int node, int vis[], stack<int>& st, vector<int> adj[]){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it, vis, st, adj);
        }

        st.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[]){
        int vis[V] = {0};
        stack<int> st;

        for(int i(0);i < V;i++){
            if(!vis[i]) dfs(i, vis, st, adj);
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }

        return ans;
    }
	string findOrder(string words[], int N, int K) {
        vector<int> adj[K];
		for(int i(0);i < N - 1;i++){
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.length(), s2.length());
            if (s1.size() > s2.size() && s1.find(s2) == 0) return "";
            for(int j(0);j < len;j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a'); break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for(auto it:topo) ans += char(it + 'a');
        return ans;
	}
};
