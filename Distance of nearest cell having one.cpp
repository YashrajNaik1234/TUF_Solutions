class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> mat){
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q;

        for(int i(0);i < n;i++){
            for(int j(0);j < m;j++){
                if(mat[i][j] == 1){
                    q.push({{i, j}, 0}); vis[i][j] = 1;
                }
                else vis[i][j] = 0;
            }
        }

        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, -1, 0, 1};

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int z = q.front().second; q.pop();

            dis[x][y] = z;

            for(int i(0);i < 4;i++){
                int Row = x + row[i], Col = y + col[i];
                if(Row >= 0 and Row < n and Col >= 0 and Col < m
                and vis[Row][Col] == 0){
                    vis[Row][Col] = 1; q.push({{Row, Col}, z + 1});
                }
            }
        }

        return dis;
    }
};
