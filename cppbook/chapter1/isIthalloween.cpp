#include <bits/stdc++.h>
using namespace std;
int main(){
    string month;
    int day;
    cin >> month >> day;
    if ( (month == "OCT" and day == 31) or (month == "DEC" and day == 25) ) cout << "yup" << endl;
    else cout << "nope" << endl;
}