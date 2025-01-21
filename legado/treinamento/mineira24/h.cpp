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
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 998244353LL
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 

// Para FFT
void get_roots(bool f, int n, vector<complex<double>>& roots) {
	const static double PI = acosl(-1);
	for (int i = 0; i < n/2; i++) {
		double alpha = i*((2*PI)/n);
		if (f) alpha = -alpha;
		roots[i] = {cos(alpha), sin(alpha)};
	}
}

template<typename T> void fft(vector<T>& a, bool f, int N, vector<int>& rev) {
	for (int i = 0; i < N; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	int l, r, m;
	vector<T> roots(N);
	for (int n = 2; n <= N; n *= 2) {
		get_roots(f, n, roots);
		for (int pos = 0; pos < N; pos += n) {
			l = pos + 0, r = pos + n/2, m = 0;
			while (m < n/2) {
				auto t = roots[m] * a[r];
				a[r] = a[l] - t;
				a[l] = a[l] + t;
				l++, r++, m++;
			}
		}
	}
	if (f) {
		auto invN = T(1) / T(N);
		for (int i = 0; i < N; i++) a[i] = a[i] * invN;
	}
}
template<typename T> vector<T> convolution(vector<T>& a, vector<T>& b) {
    vector<T> l(a.begin(), a.end()), r(b.begin(), b.end());
	int N = l.size()+r.size()-1;
	int n = 1, log_n = 0;
	while (n <= N) n *= 2, log_n++;
	vector<int> rev(n);
	for (int i = 0; i < n; i++) {
		rev[i] = 0;
		for (int j = 0; j < log_n; j++) if (i>>j&1)
			rev[i] |= 1 << (log_n-1-j);
	}
	assert(N <= n);
	l.resize(n);
	r.resize(n);
	fft(l, false, n, rev);
	fft(r, false, n, rev);
	for (int i = 0; i < n; i++) l[i] *= r[i];
	fft(l, true, n, rev);
	l.resize(N);
	return l;
}


const ll MAXM = 1e6+10;
#define EPS 1e-6
int main(){
    int n,m;
    cin >> n >> m;
    vector<complex<double>> a(MAXM, complex<double>(0,0));
    vector<complex<double>> b(MAXM, complex<double>(0,0));

    int x;
    for (int i=0; i<n; i++){
        cin >> x;
        a[x] = complex<double>(1,0);
    }
    for (int i=0; i<m; i++){
        cin >> x;
        b[x] = complex<double>(1,0);
    }
    auto c = convolution(a,b);

    ll resp = 0;
    for (complex<double> val:c){
        resp += ( ( (ll)(val.real()+EPS) * ((ll)(val.real()+EPS) -1))/2 );
    }
   
    cout << resp << endl;
}