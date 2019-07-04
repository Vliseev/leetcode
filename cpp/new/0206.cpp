// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

#include<iostream>
#include<tuple>
using namespace std;
 
class Solution {
public:
     bool isPalindrome(ListNode* head){
        ListNode* slow = head, *fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* tmp_node = slow->next;
            slow -> next = prev;
            prev = slow;
            slow = tmp_node;             
            
        }
        
        slow = fast ? slow->next : slow;
        
        while(slow){
          if(slow->val != prev->val)
            return false;
          slow = slow -> next;
          prev = prev -> next;
        }
        
        return true;
    }
};

int main(){

  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(4);
  ListNode n6(3);
  ListNode n7(2);
  ListNode n8(1);
  
  n1.next=&n2;
  n2.next=&n3;
  n3.next=&n4;
  n4.next=&n5;
  n5.next=&n6;
  n6.next=&n7;
  n7.next=&n8;
  
  ListNode* head = &n1;

  bool is_palindrome = Solution().isPalindrome(head);
  
  cout << is_palindrome <<"\n";
  
}
