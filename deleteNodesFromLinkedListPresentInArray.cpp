class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        // method - 1 with tc O(N*M)

    //     ListNode* curr = head;
    //     set<int> seen;

    //     for(int i = 0; i<nums.size(); i++){
    //         ListNode* temp = curr;
    //         ListNode* prev = nullptr;
    //         if(seen.find(nums[i]) != seen.end()) continue;
    //         while (temp) {
    //             if (temp->val == nums[i]) {
    //                 seen.insert(nums[i]);
    //                 if (temp == curr) {
    //                     curr = curr->next;
    //                     temp = curr;
    //                 } else {
    //                     prev->next = temp->next;
    //                     temp = prev->next;
    //                 }
    //             } else {
    //                 prev = temp;
    //                 temp = temp->next;
    //             }
    //         }
    //     }
    // return curr;


    //method -  1 ----> O(n) with tc O(N)
    unordered_set<int> toDelete(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            if (toDelete.count(curr->val)) {
                prev->next = curr->next;  
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};
