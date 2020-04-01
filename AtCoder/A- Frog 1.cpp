//https://atcoder.jp/contests/dp/tasks/dp_a
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
    if(idx<n-2)
        ret = min(ret,abs(arr[idx+2]-arr[idx])+dp(idx+2));
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
        cin >> arr[i];
    cout << dp(0);
}
