#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> expr;
        int result = 0;

        for(string s : tokens) {
            if(s == "+") {
                int num1 = expr.top();
                expr.pop();
                int num2 = expr.top();
                expr.pop();

                expr.push(num2+num1);
            } else if(s == "-") {
                int num1 = expr.top();
                expr.pop();
                int num2 = expr.top();
                expr.pop();

                expr.push(num2-num1);
            } else if(s == "*") {
                int num1 = expr.top();
                expr.pop();
                int num2 = expr.top();
                expr.pop();

                expr.push(num2*num1);
            } else if(s == "/") {
                int num1 = expr.top();
                expr.pop();
                int num2 = expr.top();
                expr.pop();

                expr.push(num2/num1);
            } else {
                expr.push(stoi(s));
            }
        }

        result = expr.top();
        return result;
    }
};