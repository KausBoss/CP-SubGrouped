class Solution {
public:
	vector<string> ans;
	int n;
	int address(string s){
		int n= s.length(), ret=0;
		for(int i=0; i<n; i++){if(s[i] == '.'){ret++;}}
		return ret;
	}
	void func(int i, string ip, string s){
		//base case
		if(i >= n){
			if(address(ip) == 4){
				ip.pop_back();
				ans.push_back(ip);
			}
			return;
		}
		//recursive case
		int val=0;
		for(int j=i; j<n; j++){
			val = val*10 + (s[j]-'0');
			if((val > 255) || (s[i]=='0' && val > 0) ){break;}
            if(s[i]=='0' && val==0 && j!=i){break;}
			func(j+1, ip + to_string(val) + ".", s);
		}
		return;
	}
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        n = s.length();
        if(n > 12){ return {};}
        func(0, "", s);
        return ans;
    }
};