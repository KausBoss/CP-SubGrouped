class Solution {
public:
    int numUniqueEmails(vector<string>& e) {
        int n = e.size();
        set<string> s;
        for(auto x:e){
        	string final="";
        	bool agaya = 0;
        	bool consider = 1;
        	int atTheRate = -1;
        	for(int i=0; i<x.length(); i++){
        		if(x[i] == '@'){
        			atTheRate = i;
        			break;
        		}
        		if(consider){
        			if(x[i] == '+'){
        				consider = 0;
        			}
        			else if(x[i] == '.'){
        				continue;
        			}
        			else{
        				final += x[i];
        			}
        		}
        	}
        	final += x.substr(atTheRate, x.length() - atTheRate - 1);
        	s.insert(final);
        }
        return s.size();
    }
};