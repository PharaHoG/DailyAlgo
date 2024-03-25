class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        int shorter = 0;
        int offset = 0;

        while(a && b) {
            a = a->next;
            b = b->next;
        }

        if(a) {
            shorter = 1; // b 短
            while(a) {
                a = a->next;
                offset++;
            }
        } else {
            shorter = 0; // a 短
            while(b) {
                b = b->next;
                offset++;
            }
        }

        a = headA;
        b = headB;
        if(shorter == 0) {
            while(offset--) {
                b = b->next;
            }
        } else {
            while(offset--) {
                a = a->next;
            }
        }

        while(a != b) {
            a = a->next;
            b = b->next;
        }

        return a;

    }
};