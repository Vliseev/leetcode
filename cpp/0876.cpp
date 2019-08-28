/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return nullptr;
        auto slow = head;
        auto fast = head;
        
        while(fast->next&&fast->next->next){
            fast = fast ->next->next;
            slow = slow->next;
        }
        
        if(fast->next)
            slow=slow->next;
        
        return slow;
        
    }
};
