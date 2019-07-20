//WARNING: This solution WILL get you a TLE.

#include <bits/stdc++.h>
using namespace std;

const int N = 40010;

int n;

int arr[] = {1,5,10,25,50};
long long memo[5][N];


long long dp(int idx, int cur)
{
    if(cur == n)
        return 1;
    else if(cur>n)
        return 0;
    if(idx == 5)
        return 0;
    long long &ret = memo[idx][cur];
    if(~ret)
        return ret;
    ret = 0;
    //cout << idx << " " << cur << endl;
    ret = dp(idx,cur+arr[idx]);
    ret+= dp(idx+1,cur);
    return ret;
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

    while(cin >> n)
    {
        memset(memo,-1,sizeof memo);
        long long ans = dp(0,0);
        if(ans == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are "<<ans<<" ways to produce "<<n<<" cents change." << endl;
    }

    return 0;
}
