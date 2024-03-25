class Solution {
public:
    bool isAnagram(string s, string t) {
        // 如果字符串字符数不相等返回false
        // 使用数组记录字符在第一个字符串的出现情况
        // 第二个字符串，每出现一次字符就从数组中删去
        // 如果最后字符数组中都是零，则相等
        // 若有不为零的，不相等
        if(s.size() != t.size()) 
            return false;
        
        int res[26] = {0};

        for(int i = 0; i < s.size(); i++) {
            res[s[i]-'a']++;
        }
        for(int i = 0; i < t.size(); i++) {
            res[t[i]-'a']--;
            if(res[t[i]-'a'] < 0)
                return false;
        }

        for(int i = 0; i < 26; i++) {
            if(res[i] != 0)
                return false;
        }

        return true;
    }
};