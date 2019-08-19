#include <bits/stdc++.h>
using namespace std;

const int N = 0;

string s1,s2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s1 >> s2;

    int pt1=0,pt2 = 0;

    for(; pt1 < s1.size(); pt1++)
    {
        if(pt2 == s2.size())
        {
            cout << "YES" << endl;
            return 0;
        }
        if(s1[pt1] == s2[pt2])
            pt2++;
    }
    if(pt2 == s2.size())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
