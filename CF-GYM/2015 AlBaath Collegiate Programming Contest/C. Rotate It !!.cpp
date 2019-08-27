#include <bits/stdc++.h>
using namespace std;
 
const int N = 10010;
 
int t;
int n;
long long arr[N];
 
long long sum()
{
    long long ret = 0;
    for(int i = 0; i < n; i+=2)
        ret+=arr[i];
    return ret;
}
 
void shift()
{
    int temp = arr[0];
    for(int i = 0; i<n-1; i++)
        arr[i] = arr[i+1];
    arr[n-1] = temp;
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
 
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        long long mx = -1e18;
        for(int i = 0; i < n; i++)
        {
            mx = max(mx,sum());
            shift();
        }
        cout << mx << endl;
    }
 
 
 
 
    return 0;
}
