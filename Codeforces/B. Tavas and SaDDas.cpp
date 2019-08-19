#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

string x;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> x;
    long long ans = 0;
    int num = x.size()-1;
    for(int i = 0; i<x.size(); i++)
    {
      if(x[i] == '4')
        ans+=(1<<num);
      else
        ans+=(2*(1<<num));
      num--;
    }
    cout << ans;
    return 0;
}
