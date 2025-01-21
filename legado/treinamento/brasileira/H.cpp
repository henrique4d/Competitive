#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
 
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
 
#define fi first 
#define se second 
#define pb push_back
 
#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))
 
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
 
#define mod 998244353LL
 
#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << bitset<10>(x) << ","; cout << "\b}\n"; }
#define MOD 998244353
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
// string to_upper(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
struct Point{
    ll x, y;
    Point(ll _x = -1, ll _y = -1) : x(_x), y(_y){}
    Point(const Point &o){ x = o.x, y = o.y; }
    bool operator<(const Point &o){ return x < o.x; }
    bool operator==(const Point &o){ return x == o.x && y == o.y; }
    Point operator+(const Point &o){ return Point(x + o.x, y + o.y); }
    Point operator-(const Point &o){ return Point(x - o.x, y - o.y); }
    ll operator^(const Point &o){ return x * o.y - o.x * y; }
};

istream & operator>>(istream &in, Point &p){
    in >> p.x >> p.y;
    return in;
}
ostream & operator<<(ostream &out, const Point &p){
    out << p.x << " " << p.y;
    return out;
}

const int MAXN = 10e5 + 10;


pair<Point,Point> segments[MAXN];

struct cmp{
    bool operator()(int a, int b){
        Point a1 = segments[a].first;
        Point a2 = segments[a].second;
        Point b1 = segments[b].first;
        Point b2 = segments[b].second;
        if(a1.x < b1.x) return ((a1 - b1) ^ (a2 - b1)) > 0;
        return ((b1 - a1) ^ (b2 - a1)) < 0;
    }
};
struct Event{
    Point p;
    int id, type;
    Event(const Point _p = Point(), int _id = -1, int _type = -1): p(_p), id(_id), type(_type){}
    bool operator <(const Event &e){
        if (p.x != e.p.x) return p.x < e.p.x;
        if (type != e.type) return type != e.type;
        return p.y < e.p.y;
    }
};

Event events[3*MAXN];
ll query[MAXN];
set<int, cmp> activeEvents;
ll up[MAXN];
ll lowest[MAXN];
Point dp[MAXN];
ll n,c;
ll n_events;

void sweep_line(){  
    set<int, cmp>::iterator it;
    activeEvents.insert(1);

    for (int i=1; i<n_events; i++){
        int id = events[i].id;
        int type = events[i].type;

        if (type == 0){
            activeEvents.insert(id);
            if (segments[i].first.y > segments[i].second.y){
                it = activeEvents.find(id);
                up[id] = *(++it);
            }
        }
        else if (events[i].type == 2){
            if(segments[id].first.y < segments[id].second.y){
                it = activeEvents.find(id);
                up[id] = *(++it);
            }
            activeEvents.erase(id);
        }
        else{
            lowest[id] = *(activeEvents.begin());
        }
    }
}

Point climb(int x, int id){
    if(segments[id].first.y == segments[id].second.y)
        return Point(x, segments[id].first.y);
    
    if(dp[id] == Point()){
        int nextX = (segments[id].first.y > segments[id].second.y ? segments[id].first.x : segments[id].second.x);       
        dp[id] = climb(nextX, up[id]);
    }
    return dp[id];
}


void solve(){
    cin >> n >> c;
    for (int i=0; i<n; i++){
        cin >> segments[i].first >> segments[i].second;
        if (segments[i].second < segments[i].first){
            swap(segments[i].first, segments[i].second);
        }
        events[2*i] = Event(segments[i].first, i, 0);
        events[2*i + 1] = Event(segments[i].second, i, 2);
    }

    segments[n] = make_pair(Point(-1, INT_MAX), Point(INT_MAX, INT_MAX));
    events[2*n] = Event(Point(-1,INT_MAX), n, 0);
    events[2*n + 1] = Event(Point(INT_MAX,INT_MAX), n, 2);


    for (int i=0; i<c; i++){
        cin >> query[i];
        events[i + 2*n + 2 ] = Event(Point(query[i], 0), i, 1);
    }
    n_events= 2*n + c + 2;
    sort(events, events + 2*n + c + 2);
    sweep_line();

    for(int i = 0; i < c; i++){
        if(lowest[i] == n + 1)
            cout << query[i] << "\n";
        else{
            Point p = climb(query[i], lowest[i]);
            if(p.y == INT_MAX)
                cout << p.x << "\n";
            else
                cout << p << "\n";
        }
    }


}
 
int main() {
//    optimize;
    ll T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}