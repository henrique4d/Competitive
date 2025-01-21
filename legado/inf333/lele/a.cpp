#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0)
            break;


        int v[1050] = {0};
        bool erro = false;

        for (int i = 0; i < n; i++) {
            int c, p;
            cin >> c >> p;

            if (p < 0) {
                if (i + p < 0) {
                    erro = true;
                } else {
                    if (v[i + p] == 0)
                        v[i + p] = c;
                    else
                        erro = true;
                }
            } else {
                if (i + p >= n) {
                    erro = true;
                } else {
                    if (v[i + p] == 0)
                        v[i + p] = c;
                    else
                        erro = true;
                }
            }
        }

        if (erro)
            cout << "-1";
        else {
            for (int i = 0; i < n; i++)
                if (i!=n-1)
                    cout << v[i] << " ";
                else
                    cout << v[i];

        }

        cout << endl;
    }

    return 0;
}