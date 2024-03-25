/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 先计算出链表的长度
        // 使用链表长度计算需要将多少个节点移动到头结点
        // 移动指针到目标位置
        // 移动节点到头部
        if(k == 0)
            return head;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = dummy;
        int len = 0;
        while(cur->next != nullptr) {
            len++;
            cur = cur->next;
        }

        if(len == 0) 
            return nullptr;
        int amount = k % len;
        int distance = len - amount;
        cur = dummy;
        while(distance--) {
            cur = cur->next;
        }

        ListNode *tmp = cur;
        while(cur->next) {
            cur = cur->next;
        }
        cur->next = head;
        head = tmp->next;
        tmp->next = nullptr;

        delete dummy;
        return head;
    }
};