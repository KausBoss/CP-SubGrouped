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
    int numComponents(ListNode* head, vector<int>& G) {
        map<int, bool> m;
        for(auto x:G){m[x]=1;}
        bool found=false;
    	int comp=0;
    	while(head != NULL){
    		if(m.count(head->val)){
    			if(!found){
    				comp++;
    				found=1;
    			}
    		}
    		else{
    			found=0;
    		}
            head=head->next;
    	}
    	return comp;
    }
};