/*

*/
#include <bits/stdc++.h>

using namespace std;

#define int           long long int
#define vi              vector<int>
#define pb           push_back
#define fi           first
#define si           second
#define pii          pair<int,int>
#define vii          vector<pair<int,int>>
#define F(a,n)       for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n)       for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n)      for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)     memset(a, b, sizeof a)
#define INT_SIZE     32 
#define matrix(x)    vector<vector<x>>
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;

struct TrieNode 
{ 
    int value;
    TrieNode *a[2]; 
}; 

TrieNode *newNode() 
{ 
    TrieNode *temp = new TrieNode; 
    temp->value = 0; 
    temp->a[0] = temp->a[1] = NULL; 
    return temp; 
} 

void insert(TrieNode *root, int pre_xor) 
{ 
    TrieNode *temp = root; 
    for (int i=INT_SIZE-1; i>=0; i--) 
    { 
        bool val = pre_xor & (1<<i); 
        if (temp->a[val] == NULL) 
            temp->a[val] = newNode(); 
  
        temp = temp->a[val]; 
    } 

    temp->value = pre_xor; 
} 

int query(TrieNode *root, int pre_xor) 
{ 
    TrieNode *temp = root; 
    for (int i=INT_SIZE-1; i>=0; i--) 
    { 
        bool val = pre_xor & (1<<i); 
        if (temp->a[1-val]!=NULL) 
            temp = temp->a[1-val]; 
        else if (temp->a[val] != NULL) 
            temp = temp->a[val]; 
    } 
    return pre_xor^(temp->value); 
} 
int func(int a[], int n) 
{ 
    TrieNode *root = newNode(); 
    insert(root, 0); 
  
    int result = INT_MIN, pre_xor =0; 
  
    for (int i=0; i<n; i++) 
    { 
        pre_xor = pre_xor^a[i]; 
        insert(root, pre_xor); 
        result = max(result, query(root, pre_xor)); 
    } 
    return result; 
} 

int goo(int a[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        int test = 0;
        for(int j=i; j<n; j++){
            test = (test^a[j]);
            ans = max(ans, test);
        }
    }
    return ans;
}

int32_t main() 
{ 
    #ifndef ONLINE_JUDGE
    freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
    int n;cin>>n;
    int *a = new int[n];
    F(a, n);
    if(n<= 10){
        cout<<goo(a, n);
        r eturn 0;
    }
    cout << func(a, n);  
} 