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
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

struct Robot{
    int x,y,z;
    int X,Y,Z;
};

int main(){
    Robot A, B;
    Robot C, D;
    Robot lastA, lastB;

    cin >> A.x >> A.y >> A.z >> A.X >> A.Y >> A.Z;

    cin >> B.x >> B.y >> B.z >> B.X >> B.Y >> B.Z;

    A.X -= A.x;
    A.Y -= A.y;
    A.Z -= A.z;

    B.X -= B.x;
    B.Y -= B.y;
    B.Z -= B.z;

    cout << "(" << A.x << " " << A.y << " " << A.z << ") (" << B.x << " " << B.y << " " << B.z << ")\n";

    while (A.X or A.Y or A.Z or B.X or B.Y or B.Z){
        C = A;
        D = B;

        //cout << A.X << " " << A.Y << " " << A.Z << " - " << B.X << " " << B.Y << " " << B.Z << endl;

        if (C.X != 0 and  !(A.x - lastA.x == 1 and A.X < 0 ) and !(A.x - lastA.x == -1 and A.X > 0 ) ){
            if (C.X > 0){
                C.X--;
                C.x++;
            }
            else{
                C.X++;
                C.x--;
            }   
        }
        else if (C.Y != 0 and !(A.y - lastA.y == 1 and A.Y < 0 ) and !(A.y - lastA.y == -1 and A.Y > 0 )){
            if (C.Y > 0){
                C.Y--;
                C.y++;
            }
            else{
                C.Y++;
                C.y--;
            }
        }
        else if (C.Z != 0 and !(A.z - lastA.z == 1 and A.Z < 0 ) and !(A.z - lastA.z == -1 and A.Z > 0 )){
            if (C.Z > 0){
                C.Z--;
                C.z++;
            }
            else{
                C.Z++;
                C.z--;
            }
        }

        if (D.X != 0 and  !(B.x - lastB.x == 1 and B.X < 0 ) and !(B.x - lastB.x == -1 and B.X > 0 )){
            if (D.X > 0){
                D.X--;
                D.x++;
            }
            else{
                D.X++;
                D.x--;
            }   
        }
        else if (D.Y != 0 and  !(B.y - lastB.y == 1 and B.Y < 0 ) and !(B.y - lastB.y == -1 and B.Y > 0 )){
            if (D.Y > 0){
                D.Y--;
                D.y++;
            }
            else{
                D.Y++;
                D.y--;
            }
        }
        else if (D.Z != 0 and  !(B.z - lastB.z == 1 and B.Z < 0 ) and !(B.z - lastB.z == -1 and B.Z > 0 )){
            if (D.Z > 0){
                D.Z--;
                D.z++;
            }
            else{
                D.Z++;
                D.z--;
            }
        }

        if ( (C.x == B.x and C.y == B.y and C.z == B.z and D.x == A.x and D.y == A.y and D.z == A.z) or (C.x == D.x and C.y == D.y and C.z == D.z)  ){
            //cout << "here\n";
            if (A.X or A.Y or A.Z){
                if (C.x != A.x){
                    C = A;
                    if (C.y < 0){
                        C.y++;
                        C.Y--;
                    }
                    else{
                        C.y--;
                        C.Y++;
                    }
                }else{
                    C = A;
                    if (C.x < 0){
                        C.x++;
                        C.X--;
                    }
                    else{
                        C.x--;
                        C.X++;
                    }
                }
                
            }
            else{
                if (D.x != B.x){
                    D = B;
                    if (D.y < 0){
                        D.y++;
                        D.Y--;
                    }
                    else{
                        D.y--;
                        D.Y++;
                    }
                }else{
                    D = B;
                    if (D.x < 0){
                        D.x++;
                        D.X--;
                    }
                    else{
                        D.x--;
                        D.X++;
                    }
                }
            }
        }
        lastA = A;
        lastB = B;
        A = C;
        B = D;
        
        cout << "(" << A.x << " " << A.y << " " << A.z << ") (" << B.x << " " << B.y << " " << B.z << ")\n";

    }
}