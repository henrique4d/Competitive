#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while (cin >> a){
        cin >> b;
        if (!a and !b) return 0;

        set<int> A;
        set<int> B;

        set<int> interesecao;

        for (int i=0; i<a; i++){
            int val;
            cin >> val;
            A.insert(val);
        }

        for (int i=0; i<b; i++){
            int val;
            cin >> val;
            B.insert(val);
        }

        set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(interesecao, interesecao.begin()));

        int result = min(A.size(), B.size()) - interesecao.size();
        cout << result << endl;
    }
}