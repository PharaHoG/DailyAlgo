#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int cur = 1;
        int row = 0;
        int col = 0;
        int offset = 0;

        for(; n >= 0; n -= 2) {
            if (n == 1) {
                result[row][col] = cur;
                break;
            }
            for(int i = 0; i < n - 1; i++) {
                result[row][col++] = cur++;
            }
            for(int i = 0; i < n - 1; i++) {
                result[row++][col] = cur++;
            }
            for(int i = 0; i < n - 1; i++) {
                result[row][col--] = cur++;
            }
            for(int i = 0; i < n - 1; i++) {
                result[row--][col] = cur++;
            }
            col++;
            row++;
            offset++;
        }

        return result;
    }
};

class Solution2 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int cur = 1;
        int row = 0;
        int col = 0;
        int offset = 0;

        for(; n > 2 * offset; offset++) {
            for(int i = 0; i < n - 2*offset - 1; i++) {
                result[row][col++] = cur++;
            }
            for(int i = 0; i < n - 2*offset - 1; i++) {
                result[row++][col] = cur++;
            }
            for(int i = 0; i < n - 2*offset - 1; i++) {
                result[row][col--] = cur++;
            }
            for(int i = 0; i < n - 2*offset - 1; i++) {
                result[row--][col] = cur++;
            }
            col++;
            row++;
        }

        if (n % 2 == 1) {
            result[n/2][n/2] = n*n;
        }

        return result;
    }
};

int main() {
    
    Solution2 s2;
    auto v = s2.generateMatrix(5);

    for(auto i : v) {
        for(auto j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }

}