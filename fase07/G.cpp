#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
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
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 998244353
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 

bool get_num(string &s){
    string aux = "";
    if (s == "") return false;

    for (int i=0; i<s.size(); i++){
        if (s[i] >= 'a' and s[i] <= 'z') return false;

        if (s[i] >= '0' and s[i] <= '9') aux.push_back(s[i]);
    }

    s = aux;
    return true;
} 


vector<string> mystrtok(string str, char delim){
    vector<string> tokens;
    string temp = "";
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ' or str[i] == '.' or str[i] == ','){
            tokens.push_back(temp);
            temp = "";
        }
        else
            temp += str[i];           
    }
    tokens.push_back(temp);
    return tokens;
}


void solve(){
    int n;
    cin >> n;
    cin.ignore();
    map<ll,ll> aparece;
    map<ll,ll> apareceultimo;
    
    ll cont = 2;

    for (int z=0; z<n; z++){
        string in;
        getline(cin,in);
        vector<string> tokens = mystrtok(in, ' ');
        string atual = "";

        // cout << tokens << endl;
        // for (string intermediate:tokens){
        //     cout << intermediate << endl;
        // }
        // stringstream class check1
        
        // Tokenizing w.r.t. space ' '
        
        for (string intermediate:tokens){
            //cout << intermediate << endl;

            if (!get_num(intermediate)){
                
                if (atual != ""){
                    
                    ll val = atoll(atual.c_str());
                    //cout << "o valor e " << val << endl;
                    apareceultimo[val] = max(apareceultimo[val], cont);
                    if ( aparece.find(val) == aparece.end() ){
                        aparece[val] = cont;
                    }
                    cont++;
                    atual = "";
                    //cout << "adicionando o valor " << val << endl;

                    if (aparece.find(val-2) != aparece.end() and aparece.find(val-1) != aparece.end()){
                        if (aparece[val-2] < apareceultimo[val-1]){
                            cout << "123\n";
                            return;
                        }
                    }
                }
            }
            else{
                atual += intermediate;
            }
        }
        
        if (atual != ""){
            ll val = atoll(atual.c_str());
            
            //cout << "o valor e " << val << endl;
            apareceultimo[val] = max(apareceultimo[val], cont);
            if ( aparece.find(val) == aparece.end() ){
                aparece[val] = cont;
            }
            cont++;

            atual = "";
            //cout << "adicionando o valor " << val << endl;
            
            if (aparece.find(val-2) != aparece.end() and aparece.find(val-1) != aparece.end()){
                if (aparece[val-2] < apareceultimo[val-1]){
                    cout << "123\n";
                    return;
                }
            }
        }

    }

    bool contagem = false;

    for (auto it = aparece.begin(); it!= aparece.end(); it++){
        ll index = it->first;
        //cout << index << endl;
        if (aparece.find(index) != aparece.end() and aparece.find(index+1) != aparece.end() and aparece.find(index+2) != aparece.end()){
            if (aparece[index] <= aparece[index+1] and aparece[index+1] <= aparece[index+2]) contagem = true;

        }
    }
    
    if (!contagem){
        cout << ":)\n";
        return;
    }

    cout << "123\n";
    

    
}
 
 
int main() {
 
    optimize;
    ll T = 1;
    //cin >> T;
 
    while(T--) {
        solve();
    }
 
    return 0;
}
