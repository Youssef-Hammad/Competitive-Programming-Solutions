//https://atcoder.jp/contests/dp/tasks/dp_b
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

int n,k;
int arr[N];

int memo[N];

int dp(int idx)
{
    int &ret = memo[idx];
    if(~ret)
        return ret;
    ret = 0;
    if(idx<n-1)
        ret = abs(arr[idx+1]-arr[idx])+dp(idx+1);
    for(int i = 2; i<=k; i++)
    {
        if(idx+i<n)
            ret = min(ret,abs(arr[idx+i]-arr[idx])+dp(idx+i));
        else
            break;
        
    }
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
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << dp(0);
}
