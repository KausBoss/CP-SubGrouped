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
	int lengthLL(ListNode *head){
		int len=0;
		while(head!=NULL){
			len++;
			head = head->next;
		}
		return len;
	}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = lengthLL(headA), lenB=lengthLL(headB);
        int diff = abs(lenA- lenB);
        if(lenA > lenB){
        	while(diff--){
        		headA=headA->next;
        	}
        }
        else{
        	while(diff--){
        		headB=headB->next;
        	}
        }

        while(headA != NULL && headB != NULL){
        	if(headA == headB){
        		return headA;
        	}
        	headA=headA->next;
        	headB=headB->next;
        }
        return NULL;
    }
};