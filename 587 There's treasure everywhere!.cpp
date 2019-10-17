#include <bits/stdc++.h>

using namespace std;

#define endl "\n";

const double PI = acos(-1.0);

const int N = 5010;
const double EPS=1e-7;

typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()

T cross(pt v,pt w)
{
    return (conj(v)*w).y;
}

T orientation(pt a,pt b,pt c)
{
    return cross(b-a,c-a);
}

bool inAngle(pt a,pt b,pt c,pt p)
{
    assert(orientation(a,b,c)!=0);
    if(orientation(a,b,c)<0)
        swap(b,c);
    return orientation(a,b,p)>=0&&orientation(a,c,p)<=0;
}

bool operator==(pt a,pt b)
{
    return a.x==b.x&&a.y==b.y;
}

bool operator!=(pt a,pt b)
{
    return !(a==b);
}

T sq(pt p)
{
    return p.x*p.x+p.y*p.y;
}

double abs(pt p)
{
    return sqrt(sq(p));
}

ostream& operator<<(ostream& os,pt p)
{
    return os<<"("<<p.x<<","<<p.y<<")";
}

template <typename T> int sgn(T x)
{
    return (T(0)<x)-(x<T(0));
}

T dot(pt v,pt w)
{
    return (conj(v)*w).x;
}

bool isPerp(pt v,pt w)
{
    return dot(v,w)==0;
}

pt perp(pt p)
{
    return {-p.y, p.x};
}

double angle(pt v,pt w)
{
    double cosTheta=dot(v,w)/abs(v)/abs(w);
    return acos(max(-1.0,min(1.0,cosTheta)));
}

struct line
{
    pt v; T c;
    // From direction vector v and offset c
    line(pt v, T c) : v(v), c(c) {}
    // From equation ax+by=c
    line(T a, T b, T c) : v({b,-a}), c(c) {}
    // From points P and Q
    line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
    // Will be defined later:
    // - these work with T = int
    T side(pt p)
    {
        return cross(v,p)-c;
    }
    double dist(pt p)
    {
        return fabs(side(p)) / abs(v);
    }
    double sqDist(pt p)
    {
        return side(p)*side(p) / (double)sq(v);
    }
    line perpThrough(pt p)
    {
        return {p, p + perp(v)};
    }
    bool cmpProj(pt p, pt q)
    {
        return dot(v,p) < dot(v,q);
    }
    line translate(pt t)
    {
        return {v, c + cross(v,t)};
    }
    pt proj(pt p);
    pt refl(pt p);
};


int t;

pt stLine1,enLine1,stLine2,enLine2;

bool inter(line l1,line l2,pt &out)
{
    T d = cross(l1.v, l2.v);
    //cout << d << endl;
    if (abs(d)<=EPS) return false;
    out = (l2.v*l1.c - l1.v*l2.c) / d; // requires floating-point coordinates
    return true;
}

double ptDist(pt a,pt b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

pt point;

void calcPoint(int m,int ang)
{
    point += polar(1.0 * m, ang * PI / 180.0);
}

void calcc(string m)
{
    int en = m.size()-1;
    //cout<<m<<endl;
    if(m[m.size()-2]>='A'&&m[m.size()-2]<='Z')
        en--;
    string snum="";
    for(int i = 0; i < en; i++)
        snum+=m[i];
    stringstream ss(snum);
    int num;
    ss>>num;
    if(en==m.size()-1)
    {
        if(m[en]=='S')
            point = {point.x,point.y-num};
        else if(m[en]=='N')
            point = {point.x,point.y+num};
        else if(m[en]=='E')
            point = {point.x+num,point.y};
        else if(m[en]=='W')
            point = {point.x-num,point.y};
    }
    else
    {
        if(m[en]=='N'&&m[en+1]=='E')//angle 45
            calcPoint(num,45);
        else if(m[en]=='N'&&m[en+1]=='W')
            calcPoint(num,135);
        else if(m[en]=='S'&&m[en+1]=='W')
            calcPoint(num,225);
        else
            calcPoint(num,315);
        
    }

}

void solve(string m)
{
    string temp="";
    for(int i = 0; i < m.size(); i++)
    {
        if(m[i]==',')
        {
            calcc(temp);
            temp="";
            continue;
        }
        else if(m[i]=='.')
        {
            calcc(temp);
            temp="";
            return;
        }
        temp+=m[i];  
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    string s;
    int i = 1;
    while(true)
    {
        point = {0,0};
        cin >> s;
        if(s=="END")
            break;
        else
            solve(s);

        double ansx=point.x-EPS,ansy=point.y-EPS;
        if(ansx<=EPS&&ansx>-1)
            ansx=fabs(ansx);
        if(ansy<=EPS&&ansy>-1)
            ansy=fabs(ansy);
        
        cout << "Map #"<<i++<<endl;
        cout << "The treasure is located at (" << fixed << setprecision(3) << ansx << "," << ansy<<")."<<endl;
        cout << "The distance to the treasure is " << fixed << setprecision(3) << fabs(ptDist({0,0},point)-EPS) <<"."<<endl;
        cout << endl;   
    }



    return 0;
}
