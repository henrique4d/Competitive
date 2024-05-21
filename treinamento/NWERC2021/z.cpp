#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    string s = "a";
    string resp = "DENIED";
    int time = 5;
    char trash;
    string trash2;
    int i = -1;
    int lasttime = 5;

    while (resp == "DENIED"){
        cout << s << endl;
        cin >> resp;
        cin >> resp;
        if (resp == "GRANTED") break;
        cin >> trash;
        cin >> time;
        cin >> trash2;
        if (time == 5){
            s.push_back('a');
        }
        else{
            if (time < lasttime){
                s[i]--;
            }
            else if (time != lasttime) i++;
            else if (s[i] == 'z') s[i] = 'A';
            else if (s[i] == 'Z') s[i] = '0';
            else s[i]++;
        }
        lasttime = time;
    }
}

int main(){
    int T = 1;
    while(T--){
        solve();
    }
}