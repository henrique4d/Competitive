#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

queue<char> q;

ll getVal(){
    int paridade = 0;
    char last = '(';
    if (q.front() == '(') paridade++;
    q.pop();
    ll val = 0;
 
    while (!q.empty()){
        if (paridade == 0) return val;
        if (last == ')' and q.front() == '('){
            val *= getVal();
            continue;
        } 
        if (q.front() == '(') paridade++;
        if (q.front() == ')') {
            paridade--;
            val++;
        }
        last = q.front();
        q.pop();
    }

    return val;
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=0; i<n; i++){
        q.push(s[i]);
    }
    ll val = 1;
    while (!q.empty()) val *= getVal();

    cout << val << endl;
}