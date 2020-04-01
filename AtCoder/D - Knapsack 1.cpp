//https://atcoder.jp/contests/dp/tasks/dp_d
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
const ll INF = 1e9;
const ll N2 = 1e5+10;
const int MOD = 1e9+7;

int n,w;
int arr[N];
int v[N];
ll memo[N][N2];

ll dp(int idx,int c)
{
    if(idx>=n)
        return 0;
    ll &ret = memo[idx][c];
    if(~ret)
        return ret;
    ret = dp(idx+1,c);
    if(c+arr[idx]<=w)
        ret=max(ret,dp(idx+1,c+arr[idx])+v[idx]);
    return ret;
}

int main()
{
	fastio
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

    cin >> n >> w;
    memset(memo,-1,sizeof memo);
    for(int i = 0; i < n ;i++)
        cin >> arr[i] >> v[i];
    cout << dp(0,0);
	

}
