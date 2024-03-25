#include <iostream>

// 初版，写的比较乱
// class MyLinkedList {
// private:
//     class Node {
//     public:
//         int val;
//         Node *next;
//     public:
//         Node() : val(-1), next(nullptr) {};
//         Node(int val) : val(val), next(nullptr) {};
//         Node(int val, Node *next) : val(val), next(next) {};
//     };

//     Node *head;
//     int length;

// public:
//     MyLinkedList() : head(nullptr), length(0) {}
    
//     int get(int index) {
//         if (index < 0 || index < length-1) {
//             return -1;
//         }

//         Node* dummy = new Node(0, head);
//         Node* cur = dummy->next;
//         for(int i = 0; i < index; i++) {
//             cur = cur->next;
//             // i是cur所在索引
//         }
//     }
    
//     void addAtHead(int val) {
//         Node* newhead = new Node(val, head);
//         head = newhead;
//         length++;
//     }
    
//     void addAtTail(int val) {
//         Node *dummy = new Node(-1, head);
//         Node *cur = dummy;
//         while(cur->next != nullptr) {
//             cur = cur->next;
//         }
//         cur->next = new Node(val);
//         length++;

//         head = dummy->next;
//         delete dummy;
//     }
    
//     void addAtIndex(int index, int val) {
//         Node *dummy = new Node(-1, head);
//         Node *cur = dummy;
//         int nextIndex = 0;
//         for(; nextIndex < index && cur->next != nullptr; nextIndex++, cur = cur->next) {};

//         if (nextIndex == index) {
//             Node *tmp = cur->next;
//             cur->next = new Node(val);
//             cur->next->next = tmp;
//             length++;
//         }

//         head = dummy->next;
//         delete dummy;
//     }
    
//     void deleteAtIndex(int index) {
//         Node *dummy = new Node(-1, head);
//         Node *cur = dummy;
//         int nextIndex = 0;
//         for(; nextIndex < index && cur->next != nullptr; nextIndex++, cur = cur->next) {};

//         if (nextIndex == index && cur->next != nullptr) {
//             Node *tmp = cur->next->next;
//             delete cur->next;
//             cur->next = tmp;
//             length--;
//         }

//         head = dummy->next;
//         delete dummy;
//     }

//     void printList() {
//         Node *cur = head;
//         while(cur != nullptr) {
//             std::cout << cur->val << '\n';
//             cur = cur->next;
//         }
//     }
// };

// 修正版
// 在每个函数中使用dummy
class MyLinkedList {
private:
    class Node {
    public:
        int val;
        Node *next;
    public:
        Node() : val(-1), next(nullptr) {};
        Node(int val) : val(val), next(nullptr) {};
        Node(int val, Node *next) : val(val), next(next) {};
    };

    Node *head;
    int length;

public:
    MyLinkedList() : head(nullptr), length(0) {}
    
    int get(int index) {
        if (index < 0 || index > length-1) {
            return -1;
        }

        Node* dummy = new Node(0, head);
        Node* cur = dummy->next;
        for(int i = 0; i < index; i++) {
            cur = cur->next;
            // i是cur当前所在索引
        }
        
        delete dummy;
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* newhead = new Node(val, head);
        head = newhead;
        length++;
    }
    
    void addAtTail(int val) {
        Node *dummy = new Node(-1, head);
        Node *cur = dummy;
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new Node(val);
        length++;

        head = dummy->next;
        delete dummy;
    }
    
    void addAtIndex(int index, int val) {
        // 由于单链表只能从前向后访问
        // 只有查找到下一个节点为index时
        // 能够插入新节点
        // 所以是cur->next
        if (index < 0 || index > length) {
            // 不同于 get(), index 可以等于length，此时添加到末尾
            return;
        }

        Node* dummy = new Node(0, head);
        Node* cur = dummy;
        for(int i = 0; i < index; i++) {
            cur = cur->next;
            // i是cur->next所在索引
        }
        // while(index--) {
        //     cur = cur->next;
        // }
        
        Node *tmp = cur->next;
        cur->next = new Node(val);
        length++;
        cur->next->next = tmp;

        head = dummy->next;
        delete dummy;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index > length - 1) {
            return;
        }

        Node *dummy = new Node(-1, head);
        // 是dummy还是dummy->next取决于最终操作能对哪个执行
        Node *cur = dummy; 
        for(int i = 0; i < index; i++) {
            cur = cur->next;
        }
        // while(index--) {
        //     cur = cur->next;
        // }

        // 需要删除的节点是cur->next
        Node *tmp = cur->next->next;
        delete cur->next;
        cur->next = tmp;
        length--;

        head = dummy->next;
        delete dummy;
    }
};

int main() {
    MyLinkedList ls;
    ls.addAtHead(1);
    ls.addAtTail(3);
    ls.addAtIndex(1, 2);
    std::cout << ls.get(1);
    ls.deleteAtIndex(1);
    std::cout << ls.get(1);
}