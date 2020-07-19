class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size(), j=b.size();
        int carry=0;
        while(i>=0 && j>=0){
        	int cur = (a[i]-'0') + (b[j]-'0') + carry;
        	if(cur == 1){
        		ans.push_back('1');
        		carry=0;
        	} 
        	else if(cur == 2){
        		ans.push_back('0');
        		carry=1;
        	}
        	else if(cur == 0){
        		ans.push_back('0');
        		cur=0;
        	}
        	else if(cur == 3){
        		ans.push_back('1');
        		cur = 1;
        	}
        	i--;j--;
        }
        while(i>=0){
        	int cur = (a[i]-'0') + carry;
        	if(cur == 1){
        		ans.push_back('1');
        		carry=0;
        	} 
        	else if(cur == 2){
        		ans.push_back('0');
        		carry=1;
        	}
        	else if(cur == 0){
        		ans.push_back('0');
        		cur=0;
        	}
        	i--;
        }
        while(j>=0){
        	int cur = (b[j]-'0') + carry;
        	if(cur == 1){
        		ans.push_back('1');
        		carry=0;
        	} 
        	else if(cur == 2){
        		ans.push_back('0');
        		carry=1;
        	}
        	else if(cur == 0){
        		ans.push_back('0');
        		cur=0;
        	}
        	j--;
        }
        if(carry){ans.push_back('1');}
        reverse(ans.begin(), ans.end());
        return ans;
    }
};