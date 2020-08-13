class Solution {
public:
    int dp[1001][1001];
    int N;
    int func(int size, int buffer){
        //base case
        if(size == N){
            return 0;
        }
        if(buffer + size > N){
            return 1e5;
        }
        //recursive case
        if(dp[size][buffer] != -1){return dp[size][buffer];}
        int op1 = func(size+buffer, buffer);

        if(size == buffer){
            return dp[size][buffer] = 1 + op1;
        }

        int op2 = func(size, size);

        return dp[size][buffer] = 1 + min(op1, op2);
    }
    int minSteps(int n) {
         if(n == 1){
             return 0;
         }
         N=n;
        memset(dp, -1, sizeof(dp));
        return 1 + func(1, 1);
    }
};