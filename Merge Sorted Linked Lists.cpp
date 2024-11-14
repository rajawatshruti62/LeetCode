//Coding Ninjas
#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{   
    Node<int>* dummy = new Node<int>(0); 
    Node<int>* ans = dummy;
    while(first!=NULL && second!=NULL){
        if(first->data<=second->data){
        ans->next=first;
        first=first->next;
        }
        else{
        ans->next=second;
        second=second->next;
        }
        ans=ans->next;
    }
    if(first!=NULL){
        ans->next=first;
    }
    if(second!=NULL){
        ans->next=second;
    }
    return dummy->next;
    // Write your code here.
}
