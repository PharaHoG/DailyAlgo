class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // dp[i][j] 是到 i j 的路径数
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        bool obstacle = false;
        // 初始化 dp 数组
        // 初始化第一列和第一排，如果遇到障碍物，此之后都为 0
        for (int i = 0; i < m; i++) {
            if (obstacle || obstacleGrid[i][0]) {
                obstacle = true;
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1; 
            }
        }
        obstacle = false;
        for (int i = 0; i < n; i++) {
            if (obstacle || obstacleGrid[0][i]) {
                obstacle = true;
                dp[0][i] = 0;
            } else {
                dp[0][i] = 1; 
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};