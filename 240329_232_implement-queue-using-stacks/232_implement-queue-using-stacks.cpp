#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> istack;
    stack<int> ostack;

    bool istackToOstack() {
        if(empty()) {
            return false;
        }
        if(ostack.empty()) {
            while(!istack.empty()) {
                int tmp = istack.top();
                istack.pop();
                ostack.push(tmp);
            }
        }
        return true;
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        istack.push(x);
    }
    
    int pop() {
        if(istackToOstack()) {
            int tmp = ostack.top();
            ostack.pop();
            return tmp;
        }
        return -1;
    }
    
    int peek() {
        if(istackToOstack())
            return ostack.top();
        return -1;
    }
    
    bool empty() {
        if(istack.empty() && ostack.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */