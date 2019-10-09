#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int N = 5010;

const double EPS = 1e7;

int t;

struct Point

{

    int x;

    int y;

};

Point stLine,enLine,botRight,topLeft;

bool inRect(Point p)

{

    return p.x<=botRight.x && p.x>=topLeft.x && p.y>=botRight.y&&p.y<=topLeft.y;

}

bool verIntersect(Point p1, Point p2)

{

    double slope = (p2.y-p1.y)/(p2.x-p1.x);

    double y = p2.y-slope*(p2.x-topLeft.x);

    if(y>=(double(min(p1.y,p2.y))-EPS)&&y<=(double(max(p1.y,p2.y))-EPS)&&(y<=topLeft.y&&y>=botRight.y))

        return true;

    else

    {

        y = p2.y-slope*(p2.x-botRight.x);

        if(y>=(double(min(p1.y,p2.y))-EPS)&&y<=(double(max(p1.y,p2.y))-EPS)&&(y<=topLeft.y&&y>=botRight.y))

            return true;

        return false;

    }

}

bool horIntersect(Point p1, Point p2)

{

    double slope = (p2.y-p1.y)/(p2.x-p1.x);

    double x = p2.x-((p2.y-topLeft.y)/slope);

    if(x >= double(min(p1.x,p2.x))&&x<=double(max(p1.x,p2.x))&&(x>=topLeft.x&&x<=botRight.x))

        return true;

    else

    {

        x = p2.x-((p2.y-botRight.y)/slope);

        if(x >= double(min(p1.x,p2.x))&&x<=double(max(p1.x,p2.x))&&(x>=topLeft.x&&x<=botRight.x))

            return true;

        return false;

    }

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

        cin >> stLine.x >> stLine.y >> enLine.x >> enLine.y;

        int a,b,c,d;

        cin >> a >> b >> c >> d;

        botRight.x = max(a,c);

        botRight.y = min(b,d);

        topLeft.x = min(a,c);

        topLeft.y = max(b,d);

        if(inRect(stLine)||inRect(enLine))

        {

            cout << "T" << endl;

        }

        else

        {

            if(stLine.x == enLine.x)

            {

                if(stLine.x <=botRight.x&&stLine.x>=topLeft.x)

                {

                    if((stLine.y <= topLeft.y&&enLine.y>=botRight.y)||(enLine.y<=topLeft.y&&stLine.y>=botRight.y))

                    {

                        cout << "T" << endl;

                    }

                    else

                        cout << "F" << endl;

                }

                else

                    cout << "F" << endl;

            }

            else

            {

                if(verIntersect(stLine,enLine)||horIntersect(stLine,enLine))

                    cout << "T" << endl;

                else

                    cout << "F" << endl;

            }

        }

    }

    return 0;

}
