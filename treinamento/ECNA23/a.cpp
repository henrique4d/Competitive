#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n+10, 0);
    vector<ll> menor(n+10, 0);
    vector<ll> maior(n+10, 0);

    for (int i=1; i<=n; i++){
        cin >> a[i];
        maior[i] = max(maior[i-1], a[i-1]);
    }
    a[n+1] = 1e9;
    menor[n+1] = 1e9;
    maior[n+1] = 1e9;
    for (int i=n; i>=0; i--){
        menor[i] = min(menor[i+1], a[i+1]);
    }

    vector<ll> resp;
    for (int i=1; i<=n; i++){
        if (a[i] < menor[i] and a[i] > maior[i]){
            resp.push_back(a[i]);
        }
    }

    cout << resp.size() << " ";
    for (int i=0; i<min((int)resp.size(),100); i++){
        cout << resp[i] << " ";
    }
    cout << endl;
}