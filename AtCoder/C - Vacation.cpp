//https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n";
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,bool> pllb;
typedef pair<pair<ll,ll>,ll> plll;
 
const ll N = 1e5+10;
const ll INF = 1e9;
const ll N2 = 1010;
const int MOD = 1e9+7;

int n;
int arr[N][3];

int memo[N][3];

int dp(int idx,int lastAct)
{
    if(idx==n)
        return 0;
    int &ret = memo[idx][lastAct];
    if(~ret)
        return ret;
    ret = 0;
    if(lastAct==0)
        ret = max(arr[idx][1]+dp(idx+1,1),arr[idx][2]+dp(idx+1,2));
    if(lastAct==1)
        ret = max(arr[idx][0]+dp(idx+1,0),arr[idx][2]+dp(idx+1,2));
    if(lastAct==2)
        ret = max(arr[idx][0]+dp(idx+1,0),arr[idx][1]+dp(idx+1,1));
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
    cin >> n;
	for(int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    cout << max(dp(0,0),max(dp(0,1),dp(0,2)));
}
