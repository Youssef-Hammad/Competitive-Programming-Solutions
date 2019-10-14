#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

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



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif

    cin>>t;
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    while(t--)
    {

        double a,b;
        cin>>a>>b;
        stLine1={a,b};
        cin>>a>>b;
        enLine1={a,b};
        line Line1(stLine1,enLine1);
        cin>>a>>b;
        stLine2={a,b};
        cin>>a>>b;
        enLine2={a,b};
        line Line2(stLine2,enLine2);


        pt intersectionPoint;
        if(inter(Line1,Line2,intersectionPoint))
        {
            cout<<"POINT "<<fixed<<setprecision(2)<<intersectionPoint.x<<" "<<intersectionPoint.y<<endl;
            //cout << cross(Line1.v,Line2.v)<<endl;
            
        }
        else
        {
            if(abs(orientation(stLine1,enLine1,stLine2))<=EPS || abs(orientation(stLine2,enLine2,stLine1))<=EPS)
                cout <<"LINE"<<endl;
            else
            {
                cout <<"NONE"<<endl;
            }
            
        }
        
        
    }
    cout<<"END OF OUTPUT"<<endl;



    return 0;
}
