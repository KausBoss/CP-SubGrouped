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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){return head;}
        if(head->next == NULL){
        	return head;
        }
        if(head->next->val != head->val){
        	head->next = deleteDuplicates(head->next);
        	return head;
        }
        int temp = head->val;
    	while(head!=NULL && head->val == temp){
    		head=head->next;
    	}
    	return deleteDuplicates(head);
    }
};