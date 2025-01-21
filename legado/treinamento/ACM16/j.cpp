#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define rall() v.rbegin(), v.rend()
#define ll long long
#define pii pair<int,int>

const ll MAXN = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    vector<vector<int>> acc(15, vector<int>(MAXN));

    while(t--){
        int n, q, l, r, s;
        cin >> n >> q; 
        vector<int> v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
            for (int j=1; j<=10; j++){
                acc[j][i] = acc[j][i-1];
                if (v[i]%j == 0) acc[j][i]++;
            }
        }
        
        

        f(i,q){
            cin >> l >> r >> s;

            if (!proces[s]){
                proces[s] = true;
                for (int k=1; k<=n; k++){
                    acc[s][k] = acc[s][k-1];
                    bool div = false;
                    f(j,10){
                        if ( (v[k]%(j+1) == 0) and ( (s >> j)&1) ){
                            div = true;
                            break;
                        }
                    }
                    if (div) acc[s][k]++;
                }
            }

            cout << acc[s][r] - acc[s][l-1] << endl;
        }

    }

    return 0;
}