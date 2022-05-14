#include <bits/stdc++.h>
using namespace std;
int main(){
    int time;
    char question;
    string result;
    int corrects = 0;
    int time_final = 0;
    int attempts[256];
    memset(attempts, 0, sizeof(attempts));

    while (cin >> time >> question >> result){
        if (result == "wrong") attempts[question]++;
        if (result == "right"){
            corrects++;
            time_final += time + 20* attempts[question];
        }
    }

    cout << corrects << " " << time_final << endl;
}