
#include <memory>
#include <vector>
class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    void dfs(int left,int right,string temp,vector<string> & res,int n) {
         if (left == n && right == n) {
            res.push_back(temp);
            return;
         }
         if (left < n) {
            dfs(left + 1,right,temp + "(",res,n);
         }
         if (left > right)  // 当右括号数量小于左括号时继续添加右括
         {
            dfs(left,right + 1,temp + ")",res,n);
         }
    }
    vector<string> generateParenthesis(int n) {
        // write code her
        vector<string> res;
        string temp;
        dfs(0,0,temp,res,n);
        return res;
    }
};
