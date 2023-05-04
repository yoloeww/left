
class Solution {
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    int bfs(vector<vector<char> >& grid,int a,int b) {
        queue<pair<int,int>> q;
        q.push({a,b});
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for ()
        }
    }
    int solve(vector<vector<char> >& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int count = 0;
       for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    bfs(grid,i,j);
                    count ++;
                }
        }
       }
    return count;
    }
};
