#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

long long a,b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> a >> b;
    vector<long long> ans;

    for(int i = 1; i <= sqrt(a); i++)
    {
      if(a%i == 0 && i%b == 0)
        ans.push_back(i);
      if(a%(a/i) == 0 && i != (a/i) && (a/i)%b == 0)
        ans.push_back(a/i);
    }
    sort(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++)
    {
      cout << ans[i] << " ";
    }

    return 0;
}
