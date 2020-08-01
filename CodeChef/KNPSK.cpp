#include <bits/stdc++.h>

#define D(x) cout<< #x <<" = "<<x<<"\n"
#define II() ( { int a ; read(a) ; a; } )
#define LL() ( { ll a ; read(a) ; a; } )
#define DD() ({double a; scanf("%lf", &a); a;})

using namespace std;

/* ordered set !!
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/

//Fast Reader
template<class T>inline bool read(T &x){
    int c=getchar();int sgn=1;
    while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; 
    x*=sgn; return ~c;
}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF=2e9;
const int MX=100005;
const int MOD=1000000007;
const double PI=acos(-1.0);

/*_______________________________________________*/
struct ele
{
    int o,t; ll val;
    ele(){};
    ele(int o,int t,ll val) : o(o),t(t),val(val){};
};

int main()
{
    int n = II();
    int m = 0;

    VI one,two;
    for(int i = 0; i<n; i++)
    {
        int w = II(), c = II();
        if(w == 1)
            one.push_back(c);
        else
            two.push_back(c);
        m += w;
    }

    sort(one.begin(),one.end(),greater<int>());
    sort(two.begin(),two.end(),greater<int>());

    ele fpre,spre;
    ll res[m+1];
    res[1] = (int)one.size() > 0 ? one[0] : 0;
    fpre.o = 0;
    fpre.t = -1;
    spre.t = -1;
    spre.o = -1;
    fpre.val = res[1];
    spre.val = 0;
    for(int i = 2; i<=m; i++)
    {
        ele t;
        t.o = fpre.o;
        t.t = fpre.t;
        int onePos = fpre.o+1;
        if(onePos >= (int)one.size())
            t.val = fpre.val;
        else
        {
            t.val = fpre.val + one[onePos];
            t.o++;
        }

        int twoPos = spre.t + 1;
        if(twoPos < (int)two.size())
        {
            ll temp = spre.val + two[twoPos];
            if(temp > t.val)
            {
                t.val = temp;
                t.o = spre.o;
                t.t = spre.t + 1;
            }
        }

        res[i] = t.val;

        swap(fpre,spre);
        swap(t,fpre);
    }

    for(int i = 1; i<=m; i++) printf("%lld ",res[i]);

    return 0;
}