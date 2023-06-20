#include <bits/stdc++.h>
 
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
 
#define pb push_back
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<long long int,long long int> pii;
typedef pair<ll, ll> pll;
 
#define all(x) (x).begin(),x.end()
#define endl '\n'
/* PRlong long intS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,long long int b) { if (a<b) return a; return b; }
ll min(long long int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,long long int b) { if (a>b) return a; return b; }
ll max(long long int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

long long int longest_increasing_subsequence(vector<pair<long long int, long long int>>& arr)
{
    vector<long long int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        auto it
            = lower_bound(ans.begin(), ans.end(), arr[i].second);
        if (it == ans.end()) {
            ans.push_back(arr[i].second);
        }
        else {
            *it = arr[i].second;
        }
    }
    return ans.size();
}
 


int main(){
    long long int XT, YT;
    cin >> XT >> YT;
    map<pair<long long int,long long int>,vector<pair<long long int, long long int>>> ang1;
    map<pair<long long int,long long int>,vector<pair<long long int, long long int>>> ang2;
    map<pair<long long int,long long int>,vector<pair<long long int, long long int>>> ang3;
    map<pair<long long int,long long int>,vector<pair<long long int, long long int>>> ang4;
    
    long long int n;
    cin >> n;
    long long int XL,YL, altura;
    
    f(i,0,n){
        cin >> XL >> YL >> altura;
        long long int g = __gcd(XT-XL, YT-YL);
        g = abs(g);
        //cout << g << endl;
        if (XT >= XL and YT >= YL)
            ang1[ {(XT-XL)/g, (YT-YL)/g} ].push_back({g,altura});
        else if (XT >= XL and YT < YL)
            ang2[ {(XT-XL)/g, (YT-YL)/g} ].push_back({g,altura});
        else if (XT < XL and YT >= YL)
            ang3[ {(XT-XL)/g, (YT-YL)/g} ].push_back({g,altura});
        else
            ang4[ {(XT-XL)/g, (YT-YL)/g} ].push_back({g,altura});

    }

    long long int resp = 0;


    for (auto it = ang1.begin(); it!= ang1.end(); it++){
        sort(all(it->second));
        resp += longest_increasing_subsequence(it->second );
        //print_v(it->second);
    }

    for (auto it = ang2.begin(); it!= ang2.end(); it++){
        sort(all(it->second));
        resp += longest_increasing_subsequence(it->second );
        
        //prlong long int_v(it->second);
    }

    for (auto it = ang3.begin(); it!= ang3.end(); it++){
        sort(all(it->second));
        resp += longest_increasing_subsequence(it->second );
        
        //prlong long int_v(it->second);
    }

    for (auto it = ang4.begin(); it!= ang4.end(); it++){
        sort(all(it->second));
        resp += longest_increasing_subsequence(it->second );
        //prlong long int_v(it->second);
    }

    cout << resp << endl;
}