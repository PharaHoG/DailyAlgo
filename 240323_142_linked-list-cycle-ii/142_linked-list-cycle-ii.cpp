struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        };
        if(fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        slow = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};