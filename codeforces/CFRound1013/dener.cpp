#include <bits/stdc++.h>
using namespace std;
#define optimize ios_base::sync_with_stdio(0); cin.tie(0)
#define tcase int t; cin >> t; while(t--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) sort(all(v)); (v).resize(distance((v).begin(), unique(all(v))))
#define LB(v,x) distance((v).begin(), lower_bound(all(v), x))
#define UB(v,x) distance((v).begin(), upper_bound(all(v), x))
#define COMPRESS(v) auto x=v; UNIQUE(x); for(auto &i : v) i = LB(x, i)
void YES(bool t = true) { cout << ((t)?"YES":"NO") << endl; }
void NO(bool t = true) { YES(!t); }
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1e7+10;
const int MOD = 998244353;

// 0-indexed BIT (binary indexed tree / Fenwick tree) (i : [0, len))
template <class T>
struct BIT{
    int n;
    vector<T> data;
    BIT(int len = 0) : n(len), data(len, T(0)) {}
    void reset() { fill(data.begin(), data.end(), T(0)); }
    void add(int pos, T v){ 
        // a[pos] += v
        pos++;
        while (pos > 0 and pos <= n) {
            data[pos - 1] += v;
            data[pos - 1] %= MOD;
            pos += pos & -pos;
        }
    }
    T sum(int k) const{ 
        // a[0] + ... + a[k - 1]
        T res = 0;
        while (k > 0) {
            res += data[k - 1];
            res %= MOD;
            k -= k & -k;
        }
        return res;
    }

    T sum(int l, int r) const { return sum(r) - sum(l); } // a[l] + ... + a[r - 1]
    // dbg functions
    template <class OStream>
    friend OStream &operator<<(OStream &os, const BIT &bit){
        T prv = 0;
        os << '[';
        for (int i = 1; i <= bit.n; i++){
            T now = bit.sum(i);
            os << now - prv << ',', prv = now;
        }
        return os << ']';
    }
};

void test_case() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> mat(n);
    for(string &s : mat) cin >> s;

    BIT<ll> bit2_ant(m);
    for(int i=0; i<n; i++) {
        BIT<ll> bit1(m), new_bit2_ant(m);

        for(int j=0; j<m; j++) {
            if (mat[i][j] == '#') continue;

            int l = max(0, j - d + 1);
            int r = min(m-1, j+d-1);

            if (i == 0) {
                bit1.add(j, 1);
            } else {
                bit1.add(j, bit2_ant.sum(l, r+1));
            }
        }

        for(int j=0; j<m; j++) {
            if (mat[i][j] == '#') continue;
            
            int l = max(0, j - d);
            int r = min(m-1, j+d);

            new_bit2_ant.add(j, bit1.sum(l, r+1));
        }

        bit2_ant = new_bit2_ant;
    }

    cout << bit2_ant.sum(0, m) << endl;
}

int main() {
    optimize;
    tcase test_case();
    return 0;
}