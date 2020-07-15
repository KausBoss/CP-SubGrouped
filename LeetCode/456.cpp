class Solution {
public:
    bool find132pattern(vector<int> S) {
	    stack<int> s;
	    int s3_max=INT_MIN;
	    for(int i=S.size()-1; i>=0; i--){
	    	if(S[i]<s3_max){return true;}
	    	if(s.empty()){
	    		s.push(S[i]);
	    	}
	    	else{
	    		while(!s.empty() && s.top()<S[i]){
	    			s3_max = max(s3_max, s.top());
	    			s.pop();
	    		}
	    		s.push(S[i]);
	    	}
	    	//cout<<S[i]<<" "<<s3_max<<" "<<s.size()<<endl;
	    }
	    return false;
	}
};