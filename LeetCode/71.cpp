class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string curr="";
        if(path.back() != '/'){path.push_back('/');}
        for(auto x:path){
        	if(x == '/'){
        		if(curr.empty()){
        			continue;
        		}
        		if(curr == ".." && !s.empty()){
        			s.pop();
        		}
        		else if(curr != "." && curr != ".."){
        			s.push(curr);
        		}
        		curr = "";
        	}
        	else{
        		curr.push_back(x);
        	}
        }
        if(s.empty()){return "/";}
        string ans="";
        while(!s.empty()){
        	ans = "/" + s.top() + ans;
            s.pop();
        }
        return ans;
    }
};