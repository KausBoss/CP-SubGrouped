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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //base case
        if(l1 == NULL){
        	return l2;
        }
        if(l2 == NULL){
        	return l1;
        }
        //recursive case
        ListNode *n;
        if(l1->val > l2->val){
        	n = new ListNode(l2->val, mergeTwoLists(l1, l2->next));
        }
        else{
        	n = new ListNode(l1->val, mergeTwoLists(l1->next, l2));
        }
        return n;
    }
};