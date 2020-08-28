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
	int lenList(ListNode *head){
		if(head==NULL){
			return 0;
		}
		int len =1;
		while(head){
			head=head->next;
			len++;
		}
		return len;
	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int len1=lenList(l1), len2=lenList(l2);
    	if(len2 > len1){
    		swap(l1, l2);
    	}
    	ListNode *ret=l1;
    	int carry=0;
    	while(l1){
    		if(l2){l1->val += l2->val + carry;}
    		else{l1->val += carry;}
    		if(l1->val > 9){
    			carry = 1;
    			l1->val %= 10;
    		}
    		l1=l1->next;
    		if(l2){l2=l2->next;}
    	}
    	return ret;
    }
};