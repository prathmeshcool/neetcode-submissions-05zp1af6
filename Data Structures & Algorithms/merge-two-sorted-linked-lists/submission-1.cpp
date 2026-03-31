/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* ans = nullptr;
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        if(!list1)
            return list2;
        if(!list2)
            return list1;

        if(list1->val>=list2->val){
            prev = list2;
            list2=list2->next;
        }
        else{
            prev = list1;
            list1=list1->next;
        }
        ans = prev;
        while(!(list1==NULL && list2==NULL)){
            if(!list1){
                prev->next = list2;
                return ans;
            }
            else if(!list2){
                prev->next=list1;
                return ans;
            }
            if(list1->val>=list2->val){
                ListNode* temp = new ListNode(list2->val);
                prev->next = temp;
                prev = temp;
                list2=list2->next;
            }
            else{
                ListNode* temp = new ListNode(list1->val);
                prev->next = temp;
                prev = temp;
                list1=list1->next;
            }
        }
        prev->next = nullptr;
        return ans;
    }
};
