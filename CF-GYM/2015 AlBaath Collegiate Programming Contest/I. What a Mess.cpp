#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000010;
 
int t;
int n;
int freq[N];
int num;
int arr[10000];
 
int sum(int x)
{
    if(x == 0)
        return 0;
    return (x*(x+1))/2;
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
 
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int idx = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&num);
            if(!freq[num])
                arr[idx++] = num;
            freq[num]++;
        }
        int ans = 0;
        for(int i = 0; i < idx;i++)
        {
            for(int j = 0; j<idx; j++)
            {
                if(arr[j]%arr[i] == 0)
                {
                    if(arr[i] == arr[j])
                        ans+=sum(freq[arr[i]]-1);
                    else
                        ans+= (freq[arr[i]]*freq[arr[j]]);
                }
            }
        }
        printf("%d\n",ans);
        memset(freq,0,sizeof freq);
 
    }
 
 
 
 
    return 0;
}
