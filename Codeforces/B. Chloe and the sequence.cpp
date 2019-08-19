#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n;
long long k;

long long myPow(int x, int y)
{
  long long ret = 1;
  for(int i = 0; i<y;i++)
    ret*=x;
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

    cin >> n >> k;
    if(k%2)
      cout << 1;
    else
    {
      long long size = myPow(2,n)-1;
      int cnt = 1;
      long long i = 2;
      while(i<=size/2+1)
      {
        //cout << i << endl;
        if(k%i == 0)
          cnt++;
        else
          break;
        i*=2;
      }
      cout << cnt << endl;
    }
    return 0;
}
