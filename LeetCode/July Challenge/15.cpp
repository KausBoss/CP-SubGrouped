class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string a="";
        for(auto x:s){
        	if(x == ' '){
        		if(!a.empty()){
        			v.push_back(a);
        		}
        		a="";
        	}
        	else{
        		a.push_back(x);
        	}
        }
        if(!a.empty()){
            v.push_back(a);
        }
        if(v.empty()){return "";}
        reverse(v.begin(), v.end());
        string ans="";
        for(auto x:v){
        	ans += x + " ";
        }
        ans.pop_back();
        return ans;
    }
};