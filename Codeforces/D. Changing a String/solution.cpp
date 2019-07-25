#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

string s,t;

int memo[N][N];

int dp(int i,int j)
{
    if(i>s.size()||j>t.size())
        return 1e9;
    if(i == s.size() && j == t.size())
        return 0;
    int &ret = memo[i][j];
    if(~ret)
        return ret;
    ret=1e9;
    if(i<s.size()&&j<t.size()&&s[i] == t[j])
        ret=dp(i+1,j+1);
    if(i<s.size())
        ret=min(ret,dp(i+1,j)+1);
    if(j<t.size())
        ret=min(ret,dp(i,j+1)+1);
    if(i<s.size()&&j<t.size())
        ret=min(ret,dp(i+1,j+1)+1);
    return ret;

}


void build(int i,int j)
{
    int &ret = memo[i][j];
    if(j>=t.size() && i>= s.size())
        return;
    if(s[i]==t[j])
        build(i+1,j+1);
    else
    {
        if(i<s.size() && ret == dp(i+1,j)+1)
        {
            cout << "DELETE " << j+1 << endl;
            build(i+1,j);
        }
        else if(i<s.size() && j<t.size() && ret == dp(i+1,j+1)+1)
        {
            cout << "REPLACE " << j+1 << " " << t[j] << endl;
            build(i+1,j+1);
        }
        else if (j<t.size() && ret == dp(i,j+1)+1)
        {
            cout << "INSERT " << j+1 << " " << t[j] << endl;
            build(i,j+1);
        }
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s >> t;
    memset(memo,-1,sizeof memo);
    cout << dp(0,0) << endl;
    build(0,0);
    return 0;
}
