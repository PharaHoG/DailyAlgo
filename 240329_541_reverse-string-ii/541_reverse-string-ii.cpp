#include <string>

using namespace std;

class Solution {
public:
    string& reverse(string& s, int m, int n) {
        // 翻转字符串区间写错了
        while(m < n) {
            swap(s[m], s[n]);
            m++;
            n--;
        }
        return s;
    }

    string reverseStr(string s, int k) {
        int pre = -1; // 上次翻转的字符串的末位
        int cur = 0;  // 本次需要反转的字符串末位
        int size = s.size();
        
        while(cur < size) {
            if(cur - pre == 2*k) 				{
                reverse(s, pre + 1, pre + k);
                pre = cur;
            }
            cur++;
        }

        // 由于循环后，cur++
        // 因此在结束循环后
        // pre 与 cur是左闭右开区间
        if(cur - 1 - pre <= k)
        {
            reverse(s, pre + 1, cur - 1);
        } else {
            reverse(s, pre + 1, pre + k);
        }

        return s;
    }
};