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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=l1;
        ListNode* h2=l2;

        int carry=0;
        ListNode* dummy = new ListNode(0);
        ListNode* prev;
        prev=dummy;

        while(h1 || h2 || carry){
            int v1,v2,sum;
            if(h1)v1=h1->val;
            else v1=0;

            if(h2)v2=h2->val;
            else v2=0;

            sum=v1+v2+carry;
            carry=sum/10;
            int val=sum%10;

            ListNode* curr=new ListNode(val);
            prev->next=curr;
            prev=curr;
            
            if(h1)h1=h1->next;
            if(h2)h2=h2->next;
        }

        return dummy->next;
    }
};
