#include <bits/stdc++.h>
using namespace std;

const int N = 50001;

int t;

int x,g,y,r;

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
        cin >> x >> g >> y >> r;

        if(x >= (g+y+r))
        {
            x%=(g+y+r);
        }
        if(x<g)
        {
            cout << "GREEN" << endl;
            continue;
        }
        else
            x-=g;
        if(x<y)
        {
            cout << "YELLOW" << endl;
            continue;
        }
        else
            x-=y;
        if(x<r)
            cout << "RED" << endl;
    }



    return 0;
}
