#include <vector>
const int N = 10;
bool use[N];
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        dfs(num,0,num.size());
        return res;
    }
     void dfs(vector<int> &num,int x,int n) {
        if (x >= n) {
            res.push_back(path);
            return ;
        }
        for (int i = 0; i < n; i++) {
           if(i > 0 && num[i] == num[i - 1] && use[i - 1] == false) // 树层去重
            {
                continue;
            }
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
