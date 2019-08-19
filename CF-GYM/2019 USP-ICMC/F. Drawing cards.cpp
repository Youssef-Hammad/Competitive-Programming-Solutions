#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE


    cin >> n;
    double ans = 1;
    ans+= (1.0/n)*(n-1)*n/2.0;
    cout << fixed << setprecision(13) << ans;
    return 0;
}
