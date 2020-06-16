class Solution {
public:
	float slope(vector<int> a, vector<int> b){
        if((b[0] - a[0]) == 0){return INT_MAX;}
        float slope = (b[1] - a[1]);
        slope /= (b[0] - a[0]);
        return slope;
	}
    bool checkStraightLine(vector<vector<int>>& c) {
        if(c.size() == 2){ return true; }
        float m = slope(c[1], c[0]);
        for(int i=2; i<c.size(); i++){
            float temp = slope(c[i], c[0]);
        	if(temp != m){
                cout<<temp<<"  "<<m<<endl;
        		return false;
        	}
        }
        return true;
    }
};