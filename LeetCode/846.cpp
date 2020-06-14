class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> m;
        for(auto x:hand){
        	if(m.count(x)){m[x]++;}
        	else{m[x]=1;}
        }
        for(auto it=m.begin(); it!=m.end(); it++){
        	while(it->second > 0){
        		m[it->first]--;
        		for(int i=1; i<W; i++){
        			int next = it->first + i;
        			if(m.count(next)==0 || m[next]==0){
        				return false;
        			}
        			m[next]--;
        		}
        	}
        }
        return true;
    }
};