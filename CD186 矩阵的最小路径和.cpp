#include <iostream>
using namespace std;
const int N = 2010;
int dp[N][N];
int g[N][N];
int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    dp[0][0] = g[0][0];
    for (int  i = 1; i < n; i ++) {
        dp[i][0] = dp[i - 1][0] + g[i][0];
    }
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + g[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
             dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + g[i][j];
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}
