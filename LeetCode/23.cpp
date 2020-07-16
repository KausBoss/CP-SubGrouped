
class Solution {
    ListNode* Merge(ListNode* a, ListNode* b){
        if(a==NULL){return b;}
        if(b==NULL){return a;}
        ListNode* c=NULL;
        if(a->val < b->val){
            c=a;
            c->next = Merge(a->next, b);
        }
        else{
            c=b;
            c->next= Merge(a, b->next);
        }
        return c;
    }

public:
    ListNode* mergeKLists(vector<ListNode*> lists) {
        ListNode* ret=NULL;
        for(auto x:lists){
            ret = Merge(ret, x);
        }
        return ret;
    }
};