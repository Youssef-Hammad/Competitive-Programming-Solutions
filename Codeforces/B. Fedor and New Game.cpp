#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n,m,k;
int arr[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> m >> k;
    int Fedore;
    for(int i = 0; i < m; i++)
      cin >> arr[i];
    cin >> Fedore;
    int ans =0;
    for(int i = 0; i < m; i++)
      if(__builtin_popcount(Fedore^arr[i]) <= k)
        ans++;
    cout << ans;
    return 0;
}
