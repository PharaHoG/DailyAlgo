// 初版
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;

        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy, *cur = head;

        while(cur != nullptr) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        head->next = nullptr;
        head = pre;
        delete dummy;
        return head;
    }
};