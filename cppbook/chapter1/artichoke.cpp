#include <bits/stdc++.h>
using namespace std;
int main(){
    double p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;
    double max_dif = 0;
    double max_value = p*(sin(a+b) + cos(c+d) + 2);
    for (int i=2; i<=n; i++){
        double price = p*(sin(a*i+b) + cos(c*i+d) + 2);
        max_dif = max(max_dif, max_value - price);
        max_value = max(max_value, price);
    }

    cout << fixed << setprecision(9) << max_dif << endl;
}