#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
 
/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
 
/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
 
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
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
 
/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;




// C++ program to print all prime factors
#include <bits/stdc++.h>
using namespace std;
 
// A function to print all prime
// factors of a given number n

vector<pair<int,int>> cont;
void primeFactors(int n)
{
    int atual = -1;
    // Print the number of 2s that divide n
    pair<int,int> aux = {0,0};

    while (n % 2 == 0)
    {
        if (2 != atual){
            cont.push_back(aux);
            aux.first = 2;
            aux.second = 1;
            atual = 2;
        }
        else{
            aux.second++;
        }
        //cout << 2 << " ";
        n = n/2;
    }
 
    cont.push_back(aux);
    aux = {0,0};     
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            if (i != atual){
                cont.push_back(aux);
                aux.first = i;
                aux.second = 1;
                atual = i;
            }
            else{
                aux.second++;
            }
            //cout << i << " ";
            n = n/i;
        }
    }
    
    cont.push_back(aux);        
    

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2){
        cont.push_back({n,1});        
        //cout << n << " ";

    }
}
 
/* Driver code */
int main()
{
    int z;
    scanf("%d", &z);
    f(l,0,z){
        int n;
        scanf("%d", &n);
        cont.clear();
        primeFactors(n);
        long long int final = 0;
        f(j,0,32){
            long long int resp=1;    
            f(i,0,cont.size()){
                if (cont[i].second <= 0) continue;
                //cout << "multiplicando resp por " << cont[i].first << endl;
                resp*=cont[i].first;
                cont[i].second--;
            }
            if (resp > 1)
            final+=resp;
            //cout << final << endl;
        }
        printf("%lli\n", final);
    }
}
 
// This is code is contributed by rathbhupendra








// vector<pair<int,int>> decomp(long long int n){

// }

// int main(){
//     vector<int> primes;

//     vector<bool> used(1e6);



//     int z;
//     scanf("%d", &z);
//     long long int a,b;
//     f(l,0,z){
//         long long int n;
//         scanf("%lli", &n);
//     }
// }