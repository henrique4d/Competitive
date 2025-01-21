#include <bits/stdc++.h>
using namespace std;
bool comparator (const pair<int,string>&a, const pair<int,string>&b){
    return a.first < b.first;
}

int main(){
    int t;
    cin >> t;
    for (int k=0; k<t; k++){
        pair<int, string> duplas[10];
        for (int i=0; i<10; i++){
            cin >> duplas[i].second;
            cin >> duplas[i].first;
            duplas[i].first *= -1;
        }
        stable_sort(duplas, duplas+10, comparator);

        int best = duplas[0].first;
        int i = 0;
        cout << "Case #" << k+1 << ":\n";
        while (duplas[i].first == best){
            cout << duplas[i].second << endl;
            i++;
        }
    }
}