#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string& reverseStr(string&s, int m, int n) {
        // 反转字符串s的索引m到n字符
        int size = (n - m) + 1;
        for(int i = 0; i < size/2; i++) {
            swap(s[m+i], s[n-i]);
        }

        return s;
    }
    string reverseWords(string s) {
        // 反转字符串
            // 使用左指针和右指针
        // 去除多余空格
            // 右指针找下一个字符
            // 左指针为插入的位置
        // 翻转字符串中的单词
            // 左指针为单词的第一个字符
            // 右指针为单词的末尾字符的下一个字符，空格或空
            
        //反转字符串
        int len = s.size();
        reverseStr(s, 0, len - 1);
        
        // 去除多余空格
        int left = 0, right = 0;
        int end = len - 1;

        while(s[right] == ' ') {
            right++;
        }
        while(s[end] == ' ') {
            end--;
        }

        while(right <= end) {
            if(s[right] == ' ') {
                s[left++] = ' ';
                while(s[++right] == ' ') {}
            }
            s[left++] = s[right++];
        }

        // 这个函数的边界需要注意
        // 应该删除left以后的所有的字符
        // right此时所在的不是字符串的末尾
        s.erase(left, len - left + 1);

        // 反转每两个空格或者空格与字符串头尾之间的单词
        len = s.size();
        left = 0;
        right = 0;
        while(right < len) {
            if(s[right] == ' ') {
                reverseStr(s, left, right - 1);
                left = right + 1;
            }
            right++;
        }

        if(left < right) {
            reverseStr(s, left, right - 1);
        }

        return s;
    }
};

// 原错误答案
// class Solution {
// public:
//     string& reverseStr(string&s, int m, int n) {
//         // 反转字符串s的索引m到n字符

//         int size = (m - n) + 1;
//         for(int i = 0; i < size/2; i++) {
//             swap(s[m+i], s[n-i]);
//         }

//         return s;
//     }
//     string reverseWords(string s) {
//         // 反转字符串
//             // 使用左指针和右指针
//         // 去除多余空格
//             // 右指针找下一个字符
//             // 左指针为插入的位置
//         // 翻转字符串中的单词
//             // 左指针为单词的第一个字符
//             // 右指针为单词的末尾字符的下一个字符，空格或空
            
//         //反转字符串
//         int len = s.size();
//         reverseStr(s, 0, len - 1);
        
//         // 去除多余空格
//         int left = 0, right = 0;
//         while(right < len) {
//             if(s[right] == ' ') {
//                 right++;
//                 continue;
//             }
//             s[left++] = s[right++];
//         }

//         // 反转每两个空格或者空格和字符末尾的
//         len = s.size();
//         left = 0;
//         right = 0;
//         while(right < len) {
//             if(right == ' ') {
//                 reverseStr(s, left, right - 1);
//                 left = right + 1;
//             }
//             right++;
//         }
        
//         if(left < right) {
//             reverseStr(s, left, right - 1);
//         }

//         return s;
//     }
// };

int main() {
    Solution s1;

    string s = "  hello world  ";

    s = s1.reverseWords(s);

    cout << '_' << s << '_' << '\n';
}