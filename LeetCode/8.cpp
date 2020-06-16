class Solution {
public:
    int myAtoi(string str) {
        long ret=0;
        int n=str.length();
        if(n==0)return ret;
        int i=0; bool neg=false;
        
        while(str[i]==' '&&i<n){i++;}
        
        if(str[i]=='-'||str[i]=='+'){
            if(str[i]=='-'){neg=true;}
            i++;
        }
        
        while(str[i]>=48&&str[i]<=57&&i<n){
            ret =10*ret + (str[i]-48);
                if(ret > INT_MAX){
                    return neg==true ? INT_MIN: INT_MAX;
                }
            i++;
        }
        return neg==true? -ret: ret;
    }
};