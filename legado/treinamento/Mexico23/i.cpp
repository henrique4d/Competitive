#include<bits/stdc++.h>
using namespace std;
 
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
typedef long long ll;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628
#define MOD 1000000007
 
//------------------solution starts below------------------
 
bool isvalid(int* cont, int k)
{
    for(int i = 0 ; i < 26 ; i++)
        if(cont[i] > k)
            return false;
    return true;
}
 
int tam(int* cont)
{
    int c = 0;
    for(int i = 0 ; i < 26 ; i++)
    {
        c+=cont[i];
    }
    return c;
}
 
string res(int i, int j, vector<pair<char, int>>& v)
{
    string aux = "";
    for(int a = i ; a < j ; a++)
    {
        for(int b = 0 ; b < v[a].second ; b++)
            aux+=v[a].first;
    }
    return aux;
}
 
 
bool update(int* cont, int* bcont, int k)
{
    if(isvalid(cont, k) && tam(cont) > tam(bcont))
    {
        // print(cont);
        // print(bcont);
        for(int i = 0 ; i < 26 ; i++)
        {
            bcont[i] = cont[i];
        }
        return true;
    }
 
    return false;
}
 
void solve(ll tt)
{
    int nOriginal = 0;
    int n, k, c = 0; cin >> n >> k;
    nOriginal = n;
    string s; cin >> s;
   
    
    bool dif = false;
    for(int i = 1 ; i < n ; i++)
    {
        if(s[i]!=s[i-1])
        {
            dif = true;
            break;
        }
    }
    if(!dif)
    {
        cout << -1 << endl;
        return;
    }
    
    s = s+s;
    n*=2;
 
    if(s[0]==s[n-1])
    {
        string aux = "";
 
        for(int i = n-1 ; i >=0 ; i--)
        {
            if(s[i] == s[0])
                aux+=s[i];
            else
                break;
        }
        s = aux+s.substr(0, n-aux.size());
    }
 
    vector<pair<char, int>> v;
    v.push_back({s[0], 0});
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == v[c].first)
            v[c].second++;
        else
        {
            v.push_back({s[i], 1});
            c++;
        }
    }
 
    //cout << v << endl;
 
    int i = 0, j = 1, bi = -1, bj = -1;
    int bcont[26] = {0}, cont[26] = {0};
    cont[v[0].first-'a'] = v[0].second;
    while (i<j && j<=v.size())
    {
        if(isvalid(cont, k))
        {
            cont[v[j].first-'a']+=v[j].second;
            j++;
        }
        else
        {
            if(j-i == 1)
            {
                cont[v[j].first-'a']+=v[j].second;
                j++;
            }
            cont[v[i].first-'a']-=v[i].second;
            i++;
        }
 
        if(update(cont, bcont, k))
        {
            bi = i;
            bj = j;
            //cout << res(bi, bj, v) << endl;
        }
 
    }
 
 
    string r = res(bi, bj, v);
 
    if(tam(bcont))
        if(r.size() == s.size())
        {   
            cout << s.size()/2 << endl;
            cout << r.substr(0, s.size()/2) << endl;
        }
        else if (r.size() > nOriginal){
            cout << nOriginal << endl;
            cout << r.substr(0,nOriginal) << endl;
        }
        else {
            cout << r.size() << endl;
            cout << r << endl;
        }
    else
        cout << -1 << endl;
}
 
int main()
{
    optimize;
    ll tt=1;
    //cin >> tt;
    while(tt--) solve(tt);
    //while(cin >> tt && tt) solve(tt);
 
    return 0;
}