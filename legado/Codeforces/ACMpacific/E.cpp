#include <bits/stdc++.h>
using namespace std;
int main(){
    string in;
    cin >> in;

    vector<long long int> cont(255,0);

    for (int i=0; i<in.size(); i++){
        cont[in[i]]++;
    }

    long long int resp = 1;

    for (int i='a'; i<='z'; i++){
        resp *= cont[i]+1;
        resp%=11092019;
    }

    cout << resp << endl;
}