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
	ListNode* rev(ListNode * head){
		ListNode *p=NULL, *c=head, *n;
		while(c!=NULL){
			n=c->next;
			c->next=p;
			p=c;
			c=n;
		}
		return p;
	}
    bool isPalindrome(ListNode* head) {
    	if(head == NULL){return 1;}
        ListNode *slow=head, *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
        	fast=fast->next->next;
        	slow=slow->next;
        }
        ListNode *b=slow->next;
        slow->next=NULL;
        b = rev(b);
        while(b !=NULL){
        	if(head->val != b->val){
        		return 0;
        	}
        	head=head->next;
        	b=b->next;
        }
        return 1;
    }
};