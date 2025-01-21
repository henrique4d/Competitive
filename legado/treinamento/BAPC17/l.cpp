#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    map<string,ld> m;

    int n;
    cin >> n;
    m["pink"] = 0;
    string a,b;

    long double rating;

    for (int i=0; i<n; i++){
        cin >> a >> b >> rating;
        if (m.find(b) != m.end()){
            if (m.find(a) == m.end()) m[a] = m[b] + (ld)log2(rating);
            else m[a] = max(m[a], m[b] + (ld)log2(rating));
        }
    }
    
    if (m.find("blue") == m.end()) cout << 0 << endl;
    else cout << fixed << setprecision(15) << min((ld)10,(ld)pow(2,m["blue"])) << endl;
}