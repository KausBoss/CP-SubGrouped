/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
	Node* flat(Node *head, Node *n){
		while(head->next!= NULL){
			if(head->child != NULL){
				Node *n = head->next;
				head->next = flat(head->child, n);
				head->child = NULL;
				head->next->prev = head;	
			}
			head=head->next;
		}
		if(head->child != NULL){
			head->next = flat(head->child, NULL);
			head->next->prev = head;
			head->child = NULL;
			return head;
		}
		head->next = n;
		if(head->next != NULL)head->next->prev = head;
		while(head->prev != NULL){
			head = head->prev;
		}
		return head;
	}
    Node* flatten(Node* head) {
    	if(head == NULL){return head;}
        head = flat(head, NULL);
        return head;
    }
};