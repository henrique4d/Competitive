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
 
void solve(ll tt)
{
    ll n, c = 0, c2 = 0, aux; cin >> n;
    vector<int> v;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> aux;
        if(aux == 1)
            c++;
        else if (aux == 2)
            c2++;
        else
            v.push_back(aux);
    }
 
    sort(all(v));
    bool primeiro = true;

    while (c >= 2 and c2 >= 2){
        if (c == 3 and c2 == 2){
            if (!primeiro) cout << "*";
            cout << "(1+(1+2))*(1+2)";
            primeiro = false;
            c-=3;
            c2-=2;    
        }
        else{
            if (!primeiro) cout << "*";
            cout << "(1+2)*(1+2)";
            primeiro = false;
            c-=2;
            c2-=2;
        }
        
    }
    while(c2){
        v.push_back(2);
        c2--;
    }
    sort(all(v));

    if (c == 0){
        for (auto x:v){
            if (!primeiro) cout << "*";
            cout << x;
            primeiro = false;
        }
    }
    else if (c == 1){
        if (v.empty()){
            cout << 1 << endl;
            return;
        }
        if (!primeiro) cout << "*";
        cout << "(1+" << v[0] << ")";
        primeiro = false;

        for (int i=1; i<v.size(); i++){
            if (!primeiro) cout << "*";
            cout << v[i];
            primeiro = false;
        }

    }
    else if (c == 2){
        if (!primeiro) cout << "*";
        cout << "(1+1)";
        primeiro = false;

        for (auto x:v){
            if (!primeiro) cout << "*";
            cout << x;
            primeiro = false;
        }
    }

    else if (c%3 == 0){
        for (int i=0; i<c/3; i++){
            if (!primeiro) cout << "*";
            cout << "(1+1+1)";
            primeiro = false;
        }
        for (auto x:v){
            if (!primeiro) cout << "*";
            cout << x;
            primeiro = false;
        }
    }
    else if (c%3 == 1){
        if (!v.empty() and v[0] == 2){
            if (!primeiro) cout << "*";
            cout << "(1+1+1)*(1+2)";
            primeiro = false;
            c-= 4;
            for (int i=0; i<c/3; i++){
            if (!primeiro) cout << "*";
                cout << "(1+1+1)";
                primeiro = false;
            }
            for (int j =1; j<v.size(); j++){
                if (!primeiro) cout << "*";
                cout << v[j];
                primeiro = false;
            }
            cout << endl;
            return;    
        }

        if (!primeiro) cout << "*";
        cout << "(1+1+1+1)";
        primeiro = false;
        c-= 4;

        for (int i=0; i<c/3; i++){
            if (!primeiro) cout << "*";
            cout << "(1+1+1)";
            primeiro = false;
        }
        for (auto x:v){
            if (!primeiro) cout << "*";
            cout << x;
            primeiro = false;
        }
    }
    else if (c%3 == 2){
        if (!primeiro) cout << "*";
        cout << "(1+1)";
        primeiro = false;
        c-= 2;

        for (int i=0; i<c/3; i++){
            if (!primeiro) cout << "*";
            cout << "(1+1+1)";
            primeiro = false;
        }
        for (auto x:v){
            if (!primeiro) cout << "*";
            cout << x;
            primeiro = false;
        }
    }

    cout << endl;
}
 
int main()
{
    //optimize;
    ll tt=1;
    //cin >> tt;
    while(tt--) solve(tt);
    //while(cin >> tt && tt) solve(tt);
 
    return 0;
}