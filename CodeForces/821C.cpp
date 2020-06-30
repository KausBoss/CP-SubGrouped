/*
every time we are asked to remove the element and the smallest num is not on top, we sort the 
stack in descending order. 
But sorting everytime will give TLE, hence we clear the stack everytime we need to sort.
next time when we need to remove an element and the stack is empty, it means the smallest element
is on top.
*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
#define mp           make_pair
#define pb           push_back
#define fi           first
#define si           second
#define fastIO       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)       for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)      for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)       for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n, rem=1, ans=0, num;
	string s;
	cin>>n;
	vector<int> st;
	for(int i=0; i<2*n; i++){
		cin>>s;
		if(s == "add"){
			cin>>num;
			st.pb(num);
		}
		else{
			if(st.empty()){//do nothing as smallest number is on top
				rem++;
				continue;
			}
			else if(st.back() == rem){
				st.pop_back();//no need to sort as the required element is on top
				rem++;
			}
			else if(st.back() > rem){
				st.clear();//instead of sorting we are clearing the array
				rem++;ans++;
			}
		}
	}
	cout<<ans;
}