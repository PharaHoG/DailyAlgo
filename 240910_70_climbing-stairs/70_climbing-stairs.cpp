#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

class Solution1 {
public:
    // memo[n] 爬 n 级台阶有多少种方法
    unordered_map<int, int> memo;
    int dfs(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (memo.find(n) != memo.end()) return memo[n];
        memo[n] = dfs(n-1) + dfs(n-2);
        return memo[n];
    }

    int climbStairs(int n) {
        return dfs(n);
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> dp(2);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 3; i < n + 1; i++) {
            int sum = dp[0] + dp[1];
            swap(dp[0], dp[1]);
            dp[1] = sum;
        }

        return dp[1];
    }
};

// 暴力回溯
class Solution3 {
public:
    int dfs(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        return dfs(n-1) + dfs(n-2);
    }

    int climbStairs(int n) {
        return dfs(n);
    }
};

int main() {
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;

    auto start = high_resolution_clock::now();
    // 调用需要测量的函数
    s1.climbStairs(20);
    // 获取结束时间
    auto end = high_resolution_clock::now();
    // 计算时间差，单位是微秒
    auto duration = duration_cast<microseconds>(end - start);
    cout << "s1 cost " << duration.count() << "us" << '\n';

    start = high_resolution_clock::now();
    s2.climbStairs(20);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "s2 cost " << duration.count() << "us" << '\n';
    
    start = high_resolution_clock::now();
    s3.climbStairs(20);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "s3 cost " << duration.count() << "us" << '\n';
}