class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.length(), count=0;
        int Lcount=0, Rcount=0;
        for(int i=0; i<n; i++){
        	if(s[i] == 'L'){ Lcount++;}
        	else{ Rcount++; }
        	if(Lcount == Rcount){
        		count++;
        	}
        }
        return count;
    }
};