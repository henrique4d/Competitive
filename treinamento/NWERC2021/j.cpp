#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2000;
ll a[MAXN];
int n;
bool visited[720];

void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
        cin >> a[i];
        a[i] += 180;
        a[i] *= 2;
    }

	a[n] = a[0];

	for (int i=0; i<n; i++){
		if (abs(a[i] - a[i+1]) == 360){
			cout << "yes\n";
			return;
		}
		if (abs(a[i] - a[i+1]) < 360){
			for (int j=min(a[i], a[i+1]); j<=max(a[i], a[i+1]); j++){
				visited[j] = true;
			}
		}
		else{
			for (int j=0; j<=min(a[i], a[i+1]); j++){
				visited[j] = true;
			}
			for (int j=719; j>=max(a[i], a[i+1]); j--){
				visited[j] = true;
			}
		}
	}

	for (int i=0; i<720; i++){
		if (!visited[i]){
			cout << "no\n";
			cout << fixed << setprecision(1) << (long double)i/2 - 180 << endl;
			return;
		}
	}
	cout << "yes\n";
}

int main(){
    int T = 1;
    while(T--){
        solve();
    }
}