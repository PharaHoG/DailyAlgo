// 使用 reverseLinkedList
class Solution1 {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;

        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        // 需要反转的部分的左节点
        ListNode* leftNode = pre->next; 

        // 翻转部分的右节点
        ListNode* rightNode = pre;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }

        ListNode* succ = rightNode->next;
        rightNode->next = nullptr;
        pre->next = reverseLinkedList(leftNode);
        leftNode->next = succ;

        head = dummy->next;
        delete dummy;
        return head;
    }
};

// 一次遍历后直接翻转
    // 找到left节点后，之后的每一个节点，都插入到翻转区间的起始部分

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;

        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode* leftNode = pre->next;

        ListNode* cur = leftNode->next;
        ListNode* succ = nullptr;
        ListNode* tmp = leftNode;

        for (int i = 0; i < right - left; i++) {
            succ = cur->next;
            cur->next = tmp;
            tmp = cur;
            cur = succ;
        }
        
        pre->next = tmp;
        leftNode->next = cur;

        head = dummy->next;
        delete dummy;
        return head;
    }
};