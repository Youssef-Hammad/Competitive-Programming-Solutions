#include <bits/stdc++.h>
using namespace std;

const int N = 210;
long long n,q;
long long arr[N];
long long d,m;

long long memo[N][30][20];

long long dp(long long idx,long long cur,long long rem)
{
    long long newcur = cur;
    if(newcur < 0)
        newcur = (cur%d +d)%d;
    else
        newcur%=d;
    long long &ret = memo[idx][newcur][rem];
    if(~ret)
        return ret;
    ret = 0;
    if(cur%d == 0 && !rem)
        ret++;
    if(idx == n)
        return ret;
    if(!rem)
        return ret;
    ret+=dp(idx+1,cur,rem)+dp(idx+1,cur+arr[idx],rem-1);
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int cntr = 1;
    while(cin >> n >> q)
    {
        if(!n && !q)
            break;
        int qcntr = 1;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "SET " << cntr++ << ":" << endl;
        for(int i = 0; i<q; i++)
        {
            memset(memo,-1,sizeof(memo));
            cin >> d >> m;
            cout << "QUERY " << qcntr++ << ": " << dp(0,0,m) << endl;
        }
    }


    return 0;
}
