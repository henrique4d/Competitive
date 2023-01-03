#include <bits/stdc++.h>
using namespace std;

int main(){
    int z,l;
    cin >> z;
    for(int l=0; l<z; l++){
        long double a,b, A, B,x;
        cin >> a >> b >> x;
        A = b;
        B = a;
        while (a > 0 and b > 0){
            if (a <b) swap(a,b);
            //cout << a << " " << b << endl;
            long double h = (a-b)/x;
            //cout << a << " " << b << " " << x << endl;
            if (a == x or b == x or h == (int)h){
                cout << "YES\n";
                goto here;
            }
            a =abs(a - ((int)a/b)*b) ;
        }

        // for (int i=0;a >=x or b>=x or A>=x or B>=x; i++){
        //     if (a == x or b == x or A == x or B == x){
        //         cout << "YES\n";
        //         goto here;
        //     }
        //     if (i%2){
        //         a = abs(a-b);
        //     }
        //     else{
        //         b = abs(a-b);
        //     }

        //     if (i%2){
        //         B = abs(A-B);
        //     }
        //     else{
        //         A = abs(A-B);
        //     }
        // }
        cout << "NO\n";
        here:
        int asuhhu;
    }
}