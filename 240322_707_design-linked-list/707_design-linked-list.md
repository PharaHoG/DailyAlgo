# 707. 设计链表

## 题目描述

你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：`val` 和 `next` 。`val` 是当前节点的值，`next` 是指向下一个节点的指针/引用。

如果是双向链表，则还需要属性 `prev` 以指示链表中的上一个节点。假设链表中的所有节点下标从 **0** 开始。

实现 `MyLinkedList` 类：

- `MyLinkedList()` 初始化 `MyLinkedList` 对象。
- `int get(int index)` 获取链表中下标为 `index` 的节点的值。如果下标无效，则返回 `-1` 。
- `void addAtHead(int val)` 将一个值为 `val` 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
- `void addAtTail(int val)` 将一个值为 `val` 的节点追加到链表中作为链表的最后一个元素。
- `void addAtIndex(int index, int val)` 将一个值为 `val` 的节点插入到链表中下标为 `index` 的节点之前。如果 `index` 等于链表的长度，那么该节点会被追加到链表的末尾。如果 `index` 比长度更大，该节点将 **不会插入** 到链表中。
- `void deleteAtIndex(int index)` 如果下标有效，则删除链表中下标为 `index` 的节点。

 

**示例：**

```
输入
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
输出
[null, null, null, null, 2, null, 3]

解释
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
myLinkedList.get(1);              // 返回 2
myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
myLinkedList.get(1);              // 返回 3
```



## 方法一：



**思路：**

1. 在每个函数中设置一个虚拟头结点/在类中设计一个虚拟头结点成员属性



**源代码：**

```cpp
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
```



**注意点：**

1. `cur`的值是设定为`dummy`？还是设定为`dummy->next`？
   - 取决于最后要操作的节点可使用的操作方式
     - 由于是单链表
     - 如果对`cur`所在节点**之前**增添节点，或删除`cur`节点
     - 只有通过**操作`cur`之前的节点**才可以达到这一点
   - 如果一个函数只用对当前节点操作如`get(int index)`
     - 那么将`cur`初始值设置为`dummy->next`
     - 最后获得的目标节点的指针就是`cur`本身

   - 如果必须使用目标节点的上一个节点进行操作如`addAtIndex()`
     - 那么将`cur`初始值设置为`dummy`
     - 最后获得的目标节点的指针是`cur->next`
   -  [单链表中使用dummy节点设定cur指针初始值的问题](..\Insights\单链表中使用dummy节点设定cur指针初始值的问题.md) 

