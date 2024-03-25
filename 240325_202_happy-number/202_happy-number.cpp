class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> result;

        while(n != 1) {
            int sum = 0;
            while(n != 0) {
                int tmp = n % 10;
                sum += tmp * tmp;
                n /= 10;
            }
            n = sum;
            if(result.find(n) != result.end()) {
                return false;
            } else {
                result.insert(n);
            }
        }
        return true;
    }
};