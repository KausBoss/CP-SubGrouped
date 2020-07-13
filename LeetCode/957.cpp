class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> cells, int N) {
        map<int, int> m;
        int num=999, i=1;
        while(1){
        	vector<int> t(8, 0);
        	num=0;
        	for(int j=1; j<7; j++){
        		if(cells[j-1] == cells[j+1]){
        			t[j] = 1;
        			num |= (1<<j);
        		}
        	}
        	cells = t;
        	if(i == N){
        		return cells;
        	}
        	if(m.count(num)){
        		break;
        	}
        	m[num] = i++;
        }
        N -= m[num];
        N %= (i - m[num]);
        cells = vector<int>(8, 0);
        for(int i=0; i<8; i++){
        	if(num&1){
        		cells[i]=1;
        	}
        	num = num>>1;
        }
        for(int i=0; i<N; i++){
        	vector<int> temp(8, 0);
        	for(int j=1; j<7; j++){
        		if(cells[j-1] == cells[j+1]){
        			temp[j] = 1;
        		}
        	}
        	cells = temp;
        }
        return cells;
    }
};