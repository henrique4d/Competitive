#include<bits/stdc++.h>
using namespace std;
// SHORT NAMES
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define forr(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
// #define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// CONSTANTS
const int INF = 1e9 + 7;
const double PI = 3.1415926535;
//
int t = 1;
void solve(int n)
{
    string a, b, c;
    int bestSleepTime = -1, bestStartTime = -1, lastEndTime = 0;
    map<int, int> m;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a;
//        cin.ignore();
        cin >> b;
//        cin.ignore();
        getline(cin, c);
        int start, ending;
        start = stoi(a.substr(0, 2))*60 +stoi(a.substr(3, 2));
        ending = stoi(b.substr(0, 2))*60 +stoi(b.substr(3, 2));
    

        if (m[start] < ending) m[start] = ending;
    }

    for(auto it = m.begin() ; it != m.end() ; it++)
    {
        // cout << it->first << " " << it->second << " " << lastEndTime << " " << bestSleepTime  << endl;
        if(it == m.begin())
        {
            lastEndTime = (*it).second;
            bestSleepTime = (*it).first - 600;
            bestStartTime = 600;
        }
        else
        {
            if((*it).first-lastEndTime > bestSleepTime)
            {
                bestSleepTime = (*it).first-lastEndTime;
                bestStartTime = lastEndTime;
            }
            lastEndTime =  max(lastEndTime, (*it).second);
        }
    }
    // if (t == 41){
    //     cout << "o lastendtime terminou " << lastEndTime << endl;
    // }
    if(1080-lastEndTime > bestSleepTime)
    {
        bestSleepTime = 1080-lastEndTime;
        bestStartTime = lastEndTime;
    }

    cout << "the longest nap starts at " << setw(2) << setfill('0') << bestStartTime/60 << ':' << setw(2) << setfill('0') << bestStartTime%60 << " and will last for ";
    if(bestSleepTime >= 60)
        cout << bestSleepTime/60 << " hours and ";
    cout << bestSleepTime%60 << " minutes.\n";
    // cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
    {
        cin.ignore();
        cout << "Day #" << t << ": ";
        solve(n);
        t++;
    }
    

    return 0;
}