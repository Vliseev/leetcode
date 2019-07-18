struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(slow && fast->next){
          slow = slow->next;
          fast = fast->next->next;
          if(slow == fast){
            return true;
          }
        }
        return false;
    }
};