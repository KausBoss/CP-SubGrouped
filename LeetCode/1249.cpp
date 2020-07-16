
class Solution {
public:
    string minRemoveToMakeValid(string S) {
        stack<char> s;
        string s1="";
        for(auto x:S){
        	if(x == '('){
        		s.push(x);
        		s1 += x;
        	}
        	else if(x == ')'){
        		if(!s.empty()){
        			s.pop();
        		    s1 += x;
        		}
        	}
        	else{
        		s1 += x;
        	}
        }
        int t=s.size();
        string ans="";
        cout<<s1<<endl;
        for(int i=s1.length()-1; i>=0; i--){
        	if(s1[i]=='(' && t){
        		t--;
        	}
        	else{
        		ans += s1[i];
        	}
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};