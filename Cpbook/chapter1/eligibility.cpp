#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        string name;
        int studiesYear;
        string trash;
        int birthYear;
        int courses;

        cin >> name;
        cin >> studiesYear;
        cin >> trash;
        cin >> birthYear;
        cin >> trash;
        cin >> courses;

        if (studiesYear >= 2010 or birthYear >= 1991){
            cout << name << " eligible\n"; 
        }    
        else if (courses >= 41){
            cout << name << " ineligible\n";       
        }
        else{
            cout << name << " coach petitions\n";
        }
    }
}