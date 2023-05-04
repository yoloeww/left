#include <vector>
const int N = 10;
bool use[N];
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int> > permute(vector<int> &num) {
        dfs(num,0,num.size());
        return res;
    }
    void dfs(vector<int> &num,int x,int n) {
        if (x >= n) {
            res.push_back(path);
            return ;
        }
        for (int i = 0; i < n; i++) {
            if (use[i] == false) {
                path.push_back(num[i]);
                use[i] = true;
                dfs(num,x + 1,n);
                path.pop_back();
                use[i] = false;
            }
        }

    }
};
