class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(auto x:ops){
        	if(isdigit(x[0]) || x[0]=='-'){
        		int pos = (x[0]=='-') ? 1 : 0;
        		int pb=0;
        		for(int i=pos; i<x.size(); i++){
        			pb = pb*10 + (x[i]-'0');
        		}
        		if(x[0] == '-'){pb *=-1;}
        		s.push(pb);
        	}
        	else if(x[0] == '+'){
        		int t=s.top();
        		s.pop();
        		int nw = t + s.top();
        		s.push(t);
        		s.push(nw);
        	}
        	else if(x[0] == 'D'){
        		s.push(2*s.top());
        	}
        	else if(x[0] == 'C'){
        		s.pop();
        	}
        }
        int ans=0;
        while(!s.empty()){
        	ans += s.top();
        	s.pop();
        }
        return ans;
    }
};