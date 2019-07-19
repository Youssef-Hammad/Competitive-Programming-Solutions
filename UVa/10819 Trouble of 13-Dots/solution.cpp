#include <bits/stdc++.h>
using namespace std;

const int N = 110;
long long m,n;
long long x,y;

pair<long long,long long> arr[N];
long long memo[N][10010][2];

long long dp(long long idx,long long money, bool inc)
{
    if(idx == n)
        return 0;
    long long &ret = memo[idx][money][inc];
    if(~ret)
        return ret;
    ret = dp(idx+1,money,inc);
    if(money < arr[idx].first) {
    if(abs(m-money)+arr[idx].first>2000 && !inc)
    {
        money+=200;
        inc = true;

    }}
    if(money >= arr[idx].first)
        ret = max(ret,dp(idx+1,money-arr[idx].first,inc)+arr[idx].second);
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

    bool first = false;
    while(cin >> m >> n)
    {
        memset(memo,-1,sizeof memo);
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            arr[i] = {x,y};
        }
        sort(arr,arr+n);
        cout << dp(0,m,false) << endl;
    }

    return 0;
}
