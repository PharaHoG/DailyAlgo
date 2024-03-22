struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = dummy;

        while(cur->next != nullptr) {
            if(cur->next->val == val) {
                ListNode *tmp = cur->next->next;
                delete cur->next;
                cur->next = tmp;
            } else {
                cur = cur->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};