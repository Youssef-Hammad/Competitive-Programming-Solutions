#include <bits/stdc++.h>
using namespace std;
 
const int N = 50001;
 
int t;
bool grid[8][8];
 
bool solve(int i, int j)
{
    for(int r = 0; r < 8; r++)
        if(grid[i][r] && r != j)
            return false;
    for(int c = 0; c < 8; c++)
    {
        if(grid[c][j] && c != i)
            return false;
    }
    for(int r =i,c = j; c<8 && r<8; r++,c++)
    {
        if(grid[r][c] && (r != i || c != j))
            return false;
    }
    for(int r =i,c = j; c>=0 && r>=0; r--,c--)
    {
        if(grid[r][c] && (r != i || c != j))
            return false;
    }
    for(int r =i,c = j; c>=0 && r<8; r++,c--)
    {
        if(grid[r][c] && (r != i || c != j))
            return false;
    }
    for(int r =i,c = j; c<8 && r>=0; r--,c++)
    {
        if(grid[r][c] && (r != i || c != j))
            return false;
    }
    return true;
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
        string s;
        for(int i = 0; i < 8; i++)
        {
            cin >> s;
            grid[s[0]-'A'][(s[1]-'0')-1] = true;
        }
        bool flag = false;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(grid[i][j])
                {
                    if(!solve(i,j))
                    {
                        cout << "Invalid" << endl;
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            cout << "Valid" << endl;
        memset(grid,false,sizeof grid);
    }
 
 
 
    return 0;
}
