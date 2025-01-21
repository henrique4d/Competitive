#include<bits/stdc++.h>
using namespace std;

#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(), x.end()
// #define endl '\n'
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

const ll MAX = 2000010; // Maximo input de n
const ll K = 25;
vector<bool> prime;
vector<int> allPrimes;
int operations[MAX];
vector<int> processados[MAX];

namespace sparse{
    int st[K+1][MAX], n;

    void build(int n2){
        n = n2;
        for (int i=0; i<n; i++)st[0][i] = operations[i];
        for (int i=1; (1<<i) <= n; i++){
            for (int j=0; j + (1<<i) <= n; j++){
                st[i][j] = max(st[i-1][j], st[i-1][j+ (1 << (i-1))]);
            }
        }
    }

    int query(int l, int r){
        int i = __builtin_clz(1) - __builtin_clz(r-l+1);
        return max(st[i][l], st[i][r-(1<<i)+1]);
        
    }
}


void sieve(int n)
{
    prime.assign(n+10, true);
    prime[0] = prime[1] = false;

    for(ll i = 2 ; i <= n ; i++)
    {
        if(prime[i])
        {
            for(ll j = i*i ; j <= n ; j += i)
                prime[j] = false;
            allPrimes.push_back(i);
        }
    }
}
void factorization(int n, vector<int>& res) 
{
    for (int d : allPrimes) 
    {
        if (d * d > n)
            break;
        while (n % d == 0) 
        {
            res.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        res.push_back(n);
}



void solve(ll tt)
{
    int n, q; cin >> n >> q;
    vector<int> v(n);
    vector<int> factors[n]; // Fatores do numero no indice i;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
        processados[v[i]].push_back(i);
        // if(v[i] != 1)
        //     pq.push({v[i], -i}); // Guarda indice negativo pra ordenar pelo maior numero e menor index
    }

    sieve(MAX-5);
    
    // if(pq.size())
    // {

    // }

    // vector<int> operations(n); // Numero de operacoes feitas até transformar o numero no indice i em 1

    // for(int i = 0 ; i < n ; i++)
    //     if(v[i] == 1)
    //         operations[i] = 0;


    int curr = 0;

    for(int i = 0 ; i < n ; i++) // Salva todos os fatores primos dos numeros da pq
        factorization(v[i], factors[i]);
    for (int pos = MAX-1; pos > 1; pos--){

        for (auto idx:processados[pos]){
            // cout << pos << " " << idx << endl;
            int next = pos/factors[idx].back();
            // cout << next << endl;
            factors[idx].pop_back();

            if (next == 1){
                sort(all(processados[pos]));
                for (auto x:processados[pos]){
                    curr++;
                    operations[x] = curr;
                }
                break;
            }
            else{
                processados[next].push_back(idx);
            }
            curr++;
        }
    }
    sparse::build(n+5);

    int a, b;
    while (q--)
    {
        cin >> a >> b;
        a--;
        b--;
        cout << sparse::query(a, b) << endl;
    }
}

int main()
{
    // optimize;
    ll tt=1;
    while(tt--) solve(tt);
    //while(cin >> tt && tt) solve(tt);

    return 0;
}