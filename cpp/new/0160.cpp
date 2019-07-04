struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {

  size_t getListLen(ListNode *cur){
    size_t len = 0;
    while(cur -> next){
      len++;
      cur = cur -> next;
    }
    return len;
  }
  
  ListNode *getIntersect(size_t diff,
                         ListNode *aNode,  
                         ListNode *bNode){
      for(size_t i=0;i<diff;++i)
        aNode=aNode -> next;
      if(aNode == bNode)
        return aNode;
      while(aNode -> next && bNode -> next){
            aNode = aNode -> next;
            bNode = bNode -> next;
            if (aNode == bNode)
              return aNode;
        }
       return nullptr;
  }
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *curA = headA, *curB = headB;
      ListNode *begin = nullptr, *tailA = nullptr, *tailB = nullptr;
              
      if(curA == curB)
        return curA;
          
      size_t lenA = getListLen(curA);
      size_t lebB = getListLen(curB);
     
      if(lenA > lenB)
        return  getIntersect(lenA - lenB, headA, headB);
      else
        return getIntersect(lenB - lenA, headB, headA);
      }
};
