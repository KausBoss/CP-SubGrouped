class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n = a.size();
        int val1=-1, val2=-1;
        int val1Seg=0, val2Seg=0;
        int lastOcc1=-1, lastOcc2=-1;
        int maxSeg = 0;
        for(int i=0; i<n; i++){
        	if(a[i] == val1 || val1 == -1){
        		val1Seg++;
        		val1 = a[i];
        		lastOcc1 = i;
        	}
        	else if(a[i] == val2 || val2 == -1){
        		val2Seg++;
        		val2 = a[i];
        		lastOcc2 = i;
        	}
        	else{
        		if(lastOcc1 < lastOcc2){
        			val2Seg = i - lastOcc1 - 1;
        			val1 = a[i];
        			lastOcc1 = i;
        			val1Seg = 1;
        		}
        		else{
        			val1Seg = i - lastOcc2 - 1;
        			val2 = a[i];
        			lastOcc2 = i;
        			val2Seg = 1;
        		}
        	}
        	maxSeg = max(maxSeg, val1Seg + val2Seg);
        }
        return maxSeg;
    }
};
//soved using pointers