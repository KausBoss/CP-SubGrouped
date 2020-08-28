class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1, ver2;
        int n = version1.length();
        int val=0;
        for(int i=0; i<n; i++){
        	if(version1[i] == '.'){
        		ver1.push_back(val);
        		val = 0;
        	}
        	else{val = val*10 + (version1[i] - '0');}
        }
        if(val > 0){ver1.push_back(val);}
        while(!ver1.empty() && ver1.back()==0){ver1.pop_back();}
        val=0;
        n = version2.length();
        for(int i=0; i<n; i++){
        	if(version2[i] == '.'){
        		ver2.push_back(val);
        		val = 0;
        	}
        	else{val = val*10 + (version2[i] - '0');}
        }
        if(val > 0){ver2.push_back(val);}
        while(!ver2.empty() && ver2.back()==0){ver2.pop_back();}
        int i;
        for(i=0;i<ver1.size() && i<ver2.size(); i++){
        	if(ver1[i] > ver2[i]){return 1;}
        	if(ver1[i] < ver2[i]){return -1;}
        }
        if(ver1.size() > ver2.size()){return 1;}
        if(ver1.size() < ver2.size()){return -1;}
        return 0;
    }
};