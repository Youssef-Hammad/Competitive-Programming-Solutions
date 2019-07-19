#include <bits/stdc++.h>
using namespace std;

const int N = 40;
int t,w;
int n;
int x,y;
pair<int,int> arr[N];

int memo[N][1010];
vector<pair<int,int> > ans;

int dp(int idx, int tim)
{
    if(idx == n)
        return 0;
    int &ret = memo[idx][tim];
    if(~ret)
        return ret;
    ret = dp(idx+1,tim);
    if(tim >= (arr[idx].first*w + arr[idx].first*(2*w)))
        ret = max(ret,dp(idx+1,tim-(arr[idx].first*w + arr[idx].first*(2*w)))+arr[idx].second);
    return ret;
}

void build(int idx, int tim)
{
    if(idx == n)
        return;
    int &ret = memo[idx][tim];
    if (ret == dp(idx+1, tim))
        build(idx+1,tim);
    else
    {
        ans.push_back(arr[idx]);
        build(idx+1,tim-(arr[idx].first*w + arr[idx].first*(2*w)));
    }


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
    while(cin >> t >> w && (t || w))
    {
        memset(memo,-1,sizeof memo);
        ans.clear();
        cin >> n;
        if(!first)
            first = true;
        else
            cout << endl;
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            arr[i] = {x,y};
        }
        cout << dp(0,t) << endl;
        build(0,t);
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i].first << " "  << ans[i].second << endl;
    }


    return 0;
}
