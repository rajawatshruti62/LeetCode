// Given a linked list, swap every two adjacent nodes and return its head.
// You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* prev,*curr;
        prev=head;
        curr=head->next;
        head=curr;
        while(true){
            ListNode* next = curr->next;
            curr->next = prev; 
            if (next == NULL || next->next == NULL) {
                prev->next = next;
                break;
            }
            prev->next = next->next;
            prev = next;
            curr= prev->next;
        }
        return head;
    }
};
