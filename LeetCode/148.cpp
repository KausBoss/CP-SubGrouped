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
		ListNode *s=head, *f=head->next;
		while(f!=NULL && f->next!=NULL){
			s=s->next;
			f=f->next->next;
		}
		return s;
	}
	ListNode* merge(ListNode *a, ListNode *b){
		// base case
		if(a == NULL){return b;}
		if(b == NULL){return a;}

		//recursive case
		ListNode *n;
		if(a->val > b->val){
			n = new ListNode(b->val, merge(a, b->next));
		}
		else{
			n = new ListNode(a->val, merge(a->next, b));
		}
		return n;
	}
    ListNode* sortList(ListNode* head) {
        //base case
        if(head == NULL || head->next==NULL){
        	return head;
        }
        //recursive case
        ListNode *mid = middleLL(head);
        ListNode *a=head;
        ListNode *b=mid->next;
        mid->next=NULL;

        a=sortList(a);
        b=sortList(b);

        return merge(a, b);
    }
};