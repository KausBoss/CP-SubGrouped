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
	int lengthLL(ListNode *root){
		int len=0;
		while(root!=NULL){
			len++;
			root = root->next;
		}
		return len;
	}
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans(k, NULL);
        int len = lengthLL(root);
        int big = len%k;
        int size = len/k;
        for(int i=0; i<k; i++){
        	ans[i] = root;
        	if(big){
        		int ct = size;
        		while(root != NULL && ct--){
        			root=root->next;
        		}
                if(root == NULL){break;}
        		ListNode *n = root->next;
        		root->next = NULL;
        		root = n;
        		big--;
        	}
        	else{
        		int ct = size-1;
        		while(root != NULL && ct--){
        			root=root->next;
        		}
                if(root == NULL){break;}
        		ListNode *n = root->next;
        		root->next = NULL;
        		root = n;
        	}
        }
        return ans;
    }
};