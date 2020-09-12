vector<string> ans;
void func(int i, int j, int m[MAX][MAX], int n, string s){
	//base case
	if(i<0 || i>=n || j<0 || j>=n || m[i][j]!=1){return;}
	if(i==n-1 && j==n-1){
		ans.push_back(s);
		return;
	}
	//recursive case
	m[i][j] = -1;
	func(i+1, j, m, n, s+'D');
	func(i-1, j, m, n, s+'U');
	func(i, j+1, m, n, s+'R');
	func(i, j-1, m, n, s+'L');
	m[i][j] = 1;
}
vector<string> printPath(int m[MAX][MAX], int n) {
	ans.clear();
	func(0, 0, m, n, "");
	sort(ans.begin(), ans.end());
	return ans;
}