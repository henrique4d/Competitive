#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define all(x) (x).begin(), (x).end()

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 8122345;

namespace segMin {
	ll seg[4*MAX], lazy[4*MAX];
	ll n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m),build(2*p+1, m+1, r));
	}
	void build(ll n2, ll* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
        if (seg[p] != LINF) seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return LINF;
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = min(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};


namespace segMax {
	ll seg[4*MAX], lazy[4*MAX];
	ll n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m),build(2*p+1, m+1, r));
	}
	void build(ll n2, ll* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};






int main(){
    optimize;

    int n; cin>>n;

    vector<char> c(n);
    vector<ll> l(n);
    vector<ll> p(n);

    vector<ll> lim;

    for(int i=0;i<n;i++){
        cin >> c[i] >> l[i] >> p[i];
        if(c[i]=='|'){
            lim.push_back(p[i]);
            lim.push_back(p[i]+1);
            lim.push_back(p[i]-1);

        }else{
            lim.push_back(p[i]);
            lim.push_back(p[i]+l[i]-1);
        }
    }

    lim.push_back(0);
    lim.push_back(1000000000000000001);
    // for (auto x:lim){
    //     cout << x << endl;
    // }
    sort(all(lim));

    auto it = unique(all(lim));
    lim.resize(std::distance(lim.begin(), it));

    map<ll,int> parse;

    int id = 0;
    int ant = lim.front();
    parse[ant] = id++;

    for(int i=1;i<lim.size();i++){
        if(lim[i] - ant > 1){
            parse[ant+1]= id++;
        }
        parse[lim[i]] = id++;
        ant = lim[i];
    }

    vector<ll> v(id+10,0);

    segMax::build(v.size(),v.data());
    segMin::build(v.size(),v.data());



    for(int i=0;i<n;i++){
        if(c[i]=='|'){
            int p1 = parse[p[i]];
            segMax::update(p1,p1,l[i]);
            segMin::update(p1,p1,l[i]);
            cout << "S";
        }else{
            int p1 = parse[p[i]];
            int p2 = parse[p[i] + l[i]-1];

            if(segMax::query(p1,p2) != segMin::query(p1,p2)){
                cout << "U";
            }else{
                cout << "S";
                segMax::update(p1,p2,1);
                segMin::update(p1,p2,1);
            }
        }
    }
    cout << endl;

    return 0;
}