class Solution {
public:
    vector<int> diStringMatch(string S) {
        int s=0, e=S.length();
        vector<int> ans;
        for(auto x:S){
        	if(x == 'I'){
        		ans.push_back(s++);
        	}
        	else{
        		ans.push_back(e--);
        	}
        }
        ans.push_back(s);
        return ans;
    }
};