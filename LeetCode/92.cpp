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
	ListNode* rev(ListNode *head){
		ListNode *p=NULL, *n, *c=head;
		while(c != NULL){
			n=c->next;
			c->next=p;
			p=c;
			c=n;
		}
		return p;
	}
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int pos=1;
        ListNode *temp = head;
        while(pos < m-1){
        	temp=temp->next;
        	pos++;
        }
        ListNode *a=temp->next;
        if(m == 1){a = head;}
        ListNode *temp2 = temp;
        while(pos < n){
        	temp2=temp2->next;
        	pos++;
        }
        ListNode *c = temp2->next;
        temp2->next = NULL;
        a = rev(a);
        ListNode* ret=NULL;
        if(m == 1){ret = a;}
        else{
        	ret=head;
        	temp->next=a;
        }
        head = temp;
        while(head->next!= NULL){
        	head=head->next;
        }
        head->next = c;
        return ret;
    }
};