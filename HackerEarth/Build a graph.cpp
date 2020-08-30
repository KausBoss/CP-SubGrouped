
#include<iostream>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
	freopen("../out.txt","w",stdout);
	#endif
    int n;
    cin>>n;
    if(n >= 12){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}