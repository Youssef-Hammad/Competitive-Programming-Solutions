#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e4+10;
 
int n;
int ans[N];
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
 
    scanf("%d",&n);
 
 
    int curmin,curmax;
    for(int i = 0; i<n; i++)
    {
        if(i%4)
        {
            if(i%2)
            {
                ans[0] = ans[3]-1;
                ans[1] = ans[2]+1;
                ans[2] = ans[0]-1;
                ans[3] = ans[1]+1;
            }
            else
            {
                ans[0] = ans[3]+1;
                ans[1] = ans[2]-1;
                ans[2] = ans[0]+1;
                ans[3] = ans[1]-1;
            }
        }
        else
        {
            curmin = 16*(n/4)*(i/4);
            curmax = curmin+15;
            ans[0]=curmin;
            ans[1]=curmax;
            ans[2]=curmin+1;
            ans[3]=curmax-1;
        }
        for(int j = 4; j<n; j++)
            ans[j] = ans[j-4]+16;
        for(int j = 0; j < n; j++)
            printf("%d ",ans[j]);
        printf("\n");
    }
    return 0;
}
