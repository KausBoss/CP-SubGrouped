#include<bits/stdc++.h>
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define repi(i, a, b) for(int i=(a); i>(b); i--)
#define db(x) (cerr << #x << ": " << (x) << '\n')
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define tests(t) int t; cin >> t; while(t--)
#define iceil(n, x) (((n) + (x) - 1) / (x))
#define ll long long
#define gcd __gcd
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define sz size()
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define si(a) scanf("%d", &a)
#define sll(a) scanf("%lld", &a)
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define PI acos(-1.0)
#define EPS 1e-9
#define mod 1000000007
#define MOD 1000000007
#define N 200005
using namespace std;

using namespace std;
 
bool vis[N];
double dp[N];

double P[N];

vi adj[N];
vi adjT[N];
int n, m, r;
 
double rec(int i) {
    if(i == r) return 1;
    double &ans = dp[i];
 
    if(vis[i]) return ans;
    vis[i] = 1;
    ans = 0;
    for(int j : adjT[i]) {
        ans += rec(j) * 1.0 / adj[j].sz;
    }
    return ans;
}
 
int main(){   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
     	freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m >> r;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adjT[v].pb(u);
    }
    r--;
    dp[r] = 1;
    vis[r] = 1;
 
    for(int i = 0; i < n; i++) {
        rec(i);
        if(adj[i].sz) P[i] = 0;
        else P[i] = dp[i];
    }
 
    vector<ll> v;
    double mx = 0.0;
 
    for(int i = 0; i < n; i++) {
        if(abs(P[i] - mx) <= EPS) {
            v.pb(i + 1);
        }
        else if(P[i] > mx) {
            v.clear();
            mx = P[i];
            v.pb(i + 1);
        }
    }
    for(int i : v) cout << i << ' '; cout << '\n';
}