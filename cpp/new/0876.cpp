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
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main(){

  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  ListNode n6(6);
  ListNode n7(7);
  ListNode n8(8);
  
  n1.next=&n2;
  n2.next=&n3;
  n3.next=&n4;
  n4.next=&n5;
  n5.next=&n6;
  n6.next=&n7;
  //n7.next=&n8;
  
  ListNode *head = &n1;
  
  ListNode *reverse = nullptr, *fast = head;
  while (fast && fast->next) {
      fast = fast->next->next;
      const auto head_next = head->next;
      head->next = reverse;
      reverse = head;
      head = head_next;
  }

        // If the number of the nodes is odd,
        // set the head of the tail list to the next of the median node.
  ListNode *tail = fast ? head->next : head;
  
  ListNode *h = reverse;
  
  while(h){
   std::cout<<h->val<<"->";
   h=h->next;
  }
  std::cout<<"\n";
  
  
  while(tail){
    std::cout<<tail->val<<"->";
    tail=tail->next;
  }
  std::cout<<"\n"; 
}
