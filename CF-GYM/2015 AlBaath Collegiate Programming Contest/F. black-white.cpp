#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

int t;
int a,b,c;

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
        cin >> a >> b >> c;
        if((abs(b-c)-1)%2)
            cout << "Steven" << endl;
        else
            cout << "Mikael" << endl;
    }




    return 0;
}
