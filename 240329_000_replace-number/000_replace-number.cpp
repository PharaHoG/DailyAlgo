#include <iostream>
#include <string>

using namespace std;

string changeToNumber(string& s) {
    int cur = 0;
    int count = 0;
    int len = s.size();
    
    while(cur < len) {
        if(s[cur] >= '0' && s[cur] <= '9') {
            count++;
        }
        cur++;
    }
    
    int newlen = len + 6 * count - count;
    s.resize(newlen);
    
    // 从后向前插入到新字符串
    int left = len - 1;
    int right = newlen - 1; 
    
    while(left >= 0) {
        if(s[left] >= '0' && s[left] <= '9') {
            s[right--] = 'r';
            s[right--] = 'e';
            s[right--] = 'b';
            s[right--] = 'm';
            s[right--] = 'u';
            s[right--] = 'n';
        } else {
            s[right--] = s[left];
        }
        
        left--;
    }
    
    return s;
}

int main() {
    string s = "";
    cin >> s;
    
    s = changeToNumber(s);
    cout << s;
    return 0;
}