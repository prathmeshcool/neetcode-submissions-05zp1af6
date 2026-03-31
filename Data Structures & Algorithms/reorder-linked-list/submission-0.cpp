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

    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;


        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* p1 = head;
        ListNode* p2 = reverseList(slow->next);
        slow->next = nullptr;


        while(p2){
            ListNode* p3 = p1->next;
            ListNode* p4 = p2->next;

            p1->next = p2;
            p2->next = p3;          

            p1= p3;
            p2 = p4;
        }
    }
};
