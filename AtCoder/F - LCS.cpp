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
const ll N2 = 3010;
const int MOD = 1e9+7;

string s,t;
int sz1,sz2;

int memo[N2][N2];

int dp(int idx1,int idx2)
{
    if(idx1==sz1||idx2==sz2)
        return 0;
    int &ret = memo[idx1][idx2];
    if(~ret)
        return ret;
    ret = 0;
    if(s[idx1]==t[idx2])
    {
        ret = dp(idx1+1,idx2+1)+1;
    }
    ret = max(ret,max(dp(idx1+1,idx2),dp(idx1,idx2+1)));
    return ret;
}

void build(int idx1,int idx2)
{
    if(idx1==sz1||idx2==sz2)
        return;
    
    if(memo[idx1][idx2]==dp(idx1+1,idx2))
    {
        //cout << s[idx1];
        build(idx1+1,idx2);
    }
    else if(memo[idx1][idx2]==dp(idx1,idx2+1))
    {
        //cout << s[idx1];
        build(idx1,idx2+1);
    }
    else if(memo[idx1][idx2]==dp(idx1+1,idx2+1)+1)
    {
        cout << s[idx1];
        build(idx1+1,idx2+1);
    }
}


int main()
{
	fastio
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

    memset(memo,-1,sizeof memo);

    cin >> s >> t;

    sz1=s.size();
    sz2=t.size();
    dp(0,0);
    build(0,0);

}
