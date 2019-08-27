#include <bits/stdc++.h>
using namespace std;
 
const int N = 10010;
 
int t;
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
 
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n%2)
        {
            cout << "Impossible" << endl;
            continue;
        }
        int a,b,c;
        a=n/2;
        c=n+(n/2);
        if(c%2)
        {
            cout << "Impossible" << endl;
            continue;
        }
        b = n+(c/2);
        if(b%2)
        {
            cout << "Impossible" << endl;
            continue;
        }
        c-= (c/2);
        a+=b/2;
        b-=(b/2);
        cout << a << " " << b << " " << c << endl;
    }
 
 
 
 
    return 0;
}
