class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans, *aIt;

        if (l1 == NULL && l2 == NULL) return NULL;
        if (l2 == NULL) return l1;
        if (l1 == NULL) return l2;

        if (l1->val < l2->val) {
            ans = new ListNode(l1->val);
            l1= l1->next;
        } else {
            ans = new ListNode(l2->val);
            l2 = l2->next;
        }
        aIt = ans;

        while (l1 != NULL && l2!= NULL) {
            if (l1->val < l2->val) {
                aIt->next = new ListNode(l1->val);
                l1 = l1->next;
                aIt = aIt->next;
            } else {
                aIt->next = new ListNode(l2->val);
                l2 = l2->next;
                aIt = aIt->next;
            }
        }
        if (l1!= NULL) {
            while (l1!= NULL) {
                aIt->next = new ListNode(l1->val);
                l1 = l1->next;
                aIt = aIt->next;
            }
        } else if (l2!= NULL) {
            while (l2!= NULL) {
                aIt->next = new ListNode(l2->val);
                l2 = l2->next;
                aIt = aIt->next;
            }
        }
        return ans;
    }
};
