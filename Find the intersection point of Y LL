class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2){
            if(temp1) temp1 = temp1 -> next;
            else temp1 = headB;
            
            if(temp2) temp2 = temp2 -> next;
            else temp2 = headA;

            if(temp1 == temp2) return temp1;
        }

        return temp1;
    }
};
