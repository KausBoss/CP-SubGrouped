class Solution {
public:
	static bool func(string a, string b){
		if(a[1] == '='){return 1;}
		else{return 0;}
	}
    map<char, char> p;
    char getParent(char ch){
    	return p[ch] == ch ? ch : getParent(p[ch]);
    }
    bool equationsPossible(vector<string>& equations) {
    	sort(equations.begin(), equations.end(), func);
        for(string str:equations){
        	p[str[0]] = str[0];
        	p[str[3]] = str[3];
        }
        for(string str:equations){
        	if(str[1] == '!'){
        		if(getParent(str[0]) == getParent(str[3])){return 0;}
        	}
        	else{
        		p[str[3]] = getParent(str[0]);
        	}
        }
        return 1;
    }
};