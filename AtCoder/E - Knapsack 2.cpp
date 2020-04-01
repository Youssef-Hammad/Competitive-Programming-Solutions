//https://atcoder.jp/contests/dp/tasks/dp_e
#include <bits/stdc++.h>
    
using namespace std;
    
#define endl "\n";
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,bool> pllb;
typedef pair<pair<ll,ll>,ll> plll;
    
const ll N = 110;
const ll INF = 1e17;
const ll N2 = 1e5+10;
const int MOD = 1e9+7;
    
ll n,w;
ll weight[N],val[N];
ll memo[N][N2];
    
ll dp(int idx,int v)
{
    if(idx==n)
    {
        if(v==0)
            return 0;
        else
            return 1e14;
        
    }
    ll &ret = memo[idx][v];
    if(~ret)
        return ret;
    ret = dp(idx+1,v);
    if(val[idx]<=v)
        ret = min(ret,dp(idx+1,v-val[idx])+weight[idx]);
    return ret;
}
    
    
int main()
{
    fastio
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    
    
    memset(memo,-1,sizeof memo);
    cin >> n >> w;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> weight[i] >> val[i];
        sum+=val[i];
    }
    ll ans = 0;
    for(int i = 0; i <= sum; i++)
    {
        ll temp = dp(0,i);
        if(temp<=w)
            ans = i;
    }
    cout << ans << endl;
    
}
