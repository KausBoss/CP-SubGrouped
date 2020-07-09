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
	ListNode* middleLL(ListNode *head){
		ListNode *slow=head, *fast=head->next;
		while(fast!=NULL && fast->next!=NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	ListNode* reverseLL(ListNode *head){
		ListNode *p=NULL, *n, *c=head;
		while(c!=NULL){
			n = c->next;
			c->next = p;
			p = c;
			c = n;
		}
		return p;
	}
	ListNode* merge(ListNode *&a, ListNode *&b){
        if(b == NULL){return a;}
        if(a == NULL){return b;}
		ListNode *n=a->next;
		a->next = merge(b, n);
		return a;
	}
    void reorderList(ListNode* head) {
    	if(head ==NULL || head->next == NULL || head->next->next == NULL){return;}
        ListNode *mid = middleLL(head);
        ListNode *b = mid->next;
        mid->next = NULL;
        b = reverseLL(b);
        head = merge(head, b);
    }
};