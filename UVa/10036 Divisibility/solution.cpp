#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

int t;
int n,k;
int arr[N];
int memo[N][100];

int dp(int idx, int num)
{
    if(idx==n)
    {
        num=((num%k)+k)%k;
        if(num==0)
            return 1;
        //cout << num << endl;
        return 0;
    }
    num=((num%k)+k)%k;
    int &ret = memo[idx][num];
    if(~ret)
        return ret;
    ret = 0;
    ret=max(dp(idx+1,num+arr[idx]),dp(idx+1,num-arr[idx]));
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

    cin >> t;
    while(t--)
    {
        memset(memo,-1,sizeof memo);
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        if(dp(1,arr[0]))
            cout << "Divisible" << endl;
        else
            cout << "Not divisible" << endl;

    }


    return 0;
}
