#include <bits/stdc++.h>
 
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
 
#define pb push_back
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
 
#define all(x) (x).begin(),x.end()
#define endl '\n'
/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }


struct Point
{
    int x, y;
};
  
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
  
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
  

vector<Point> hull;
  
void convexHull(Point points[], int n)
{
    if (n < 3) return;
  
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
  
    int p = l, q;
    do
    {
        hull.push_back(points[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
  
        p = q;
  
    } while (p != l);
  
}


long double minDistance(Point A, Point B, Point E)
{
 
    // vector AB
    pair<long double, long double> AB;
    AB.fi = B.x - A.x;
    AB.se = B.y - A.y;
 
    // vector BP
    pair<long double, long double> BE;
    BE.fi = E.x - B.x;
    BE.se = E.y - B.y;
 
    // vector AP
    pair<long double, long double> AE;
    AE.fi = E.x - A.x,
    AE.se = E.y - A.y;
 
    // Variables to store dot product
    long double AB_BE, AB_AE;
 
    // Calculating the dot product
    AB_BE = (AB.fi * BE.fi + AB.se * BE.se);
    AB_AE = (AB.fi * AE.fi + AB.se * AE.se);
 
    // Minimum distance from
    // point E to the line segment
    long double reqAns = 0;
 
    // Finding the perpendicular distance
    long double x1 = AB.fi;
    long double y1 = AB.se;
    long double x2 = AE.fi;
    long double y2 = AE.se;
    long double mod = sqrt(x1 * x1 + y1 * y1);
    reqAns = abs(x1 * y2 - y1 * x2) / mod;

    return reqAns;
}


int main(){
    int n;
    cin >> n;
    Point v[n];
    f(i,0,n){
        cin >> v[i].x;
        cin >> v[i].y;
    }
    convexHull(v,n);

    long double menor_dist = -1;

    for (int i=0; i<hull.size(); i++){
        long double mais_longe = 0;
        for (int j=0; j<n; j++){
            if (i < hull.size()-1){
                mais_longe = max(mais_longe, minDistance(hull[i], hull[i+1], v[j]));
            }
            else{
                mais_longe = max(mais_longe, minDistance(hull[i], hull[0], v[j]));
            }
        }
        if (menor_dist == -1) menor_dist = mais_longe;
        menor_dist = min(menor_dist, mais_longe);
    }

    cout << fixed << setprecision(6) << menor_dist << endl;
    
}