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
    ListNode* partition(ListNode* head, int x) {
        ListNode *sh=NULL, *sp=NULL, *bh=NULL, *bp=NULL;
        while(head != NULL){
        	if(head->val < x){
        		if(sp ==NULL){
        			sp = head;
        			sh = head;
        		}
        		else{
        			sp->next = head;
        			sp = sp->next;
        		}
        	}
        	else{
        		if(bp == NULL){
        			bh = head;
        			bp = head;
        		}
        		else{
        			bp->next = head;
        			bp = bp->next;
        		}
        	}
        	head = head->next;
        }
        if(sh == NULL){return bh;}
        if(bp != NULL){bp->next = NULL;}
        sp->next = bh;
        return sh;
    }
};