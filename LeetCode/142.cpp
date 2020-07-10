/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next == NULL){return NULL;}
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next != NULL){
        	slow = slow->next;
        	fast = fast->next->next;
        	if(slow == fast){
        		break;
        	}
        }
        if(fast != slow){return NULL;}
        while(head != fast){
        	head = head->next;
        	fast = fast->next;
        }
        return head;
    }
};
