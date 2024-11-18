//You are given a linked list containing N nodes where each node is associated with a certain value. 
//Return a linked list as follows: If the input linked list is 1-->2-->3-->4, then the output should be 1-->4-->2-->3. And if the input is 1-->2-->3-->4-->5, then the output should be 1-->5-->2-->4-->3.
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

Node* modifyLL(Node* head) {
    if (!head || !head->next)  // Corrected condition
        return head;

    Node* slow = head;
    Node* fast = head;

    // Find the middle node
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    Node* secondHalf = reverseLL(slow);
    Node* firstHalf = head;

    // Merge the two halves
    Node dummy(0);
    Node* curr = &dummy;

    while (secondHalf && firstHalf != slow) {
        curr->next = firstHalf;
        firstHalf = firstHalf->next;
        curr = curr->next;

        curr->next = secondHalf;
        secondHalf = secondHalf->next;
        curr = curr->next;
    }

    if (firstHalf != slow) {
        curr->next = firstHalf;
    }

    return dummy.next;
}
