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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ret=NULL;
        while(head!=NULL && head->val == val){
        	head=head->next;
        }
        ret=head;
        while(head!=NULL && head->next!=NULL){
        	ListNode *temp=head->next;
        	while(temp!=NULL && temp->val == val){
        		temp=temp->next;
        	}
        	head->next=temp;
            head=head->next;
        }
        return ret;
    }
};