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
    int Size(ListNode* head){
        int size = 0;
        
        while(head){
            head = head->next;
            size++;
        }
        return size;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* p1 = head;


        int size = Size(head);

        if(n==1){
            if(size==1){
                return NULL;
            }
            ListNode* prev = nullptr;
            while(head && head->next){
                prev = head;
                head = head->next;
            }
            prev->next = nullptr;
            return p1;
        }
        if(n==size){
            return head->next;
        }

        for(int i = 0; i<size-n-1;i++){
            head = head->next;
        }
        ListNode* next = head->next->next;
        head->next = next;

        return p1;


    }
};
