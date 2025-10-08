class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode* ans;
       ListNode* temp1 = list1;
       ListNode* temp2 = list2;

        if(!list2){
        return list1;
        }
       
       if(!list1){
        return list2;
       }

       if(list1 && list2){
            if(list1 -> val < list2 -> val){
                ans  = new ListNode(list1 -> val);
                temp1 = list1 -> next;

            }else{
                ans = new ListNode(list2 -> val);
                temp2 = list2 -> next;
            }
       }

       ListNode* head = ans;
       ListNode* tail = ans;

       while(temp1 && temp2){
            if(temp1 -> val < temp2 -> val){
                tail -> next = new ListNode(temp1 -> val);
                temp1 = temp1 -> next;
                tail = tail -> next;
                
            }else{
                tail -> next = new ListNode(temp2 -> val);
                temp2 = temp2 -> next;
                tail = tail -> next;
            }
       }

       while(temp1){
    
        tail -> next = new ListNode(temp1 -> val);
        temp1 = temp1 -> next;
        tail = tail -> next;
       }

       while(temp2){
        tail -> next = new ListNode(temp2 -> val);
        temp2 = temp2 -> next;
        tail = tail -> next;
       }


       return head;
    }
};
