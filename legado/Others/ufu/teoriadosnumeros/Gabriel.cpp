#include <iostream>
using namespace std;
int main(){
    string auxiliar;
    cin >> auxiliar;

    if (auxiliar.size() > 10){
        auxiliar = auxiliar.substr(auxiliar.size()-10,auxiliar.size());
    }
    long long int a,b;
    cout << auxiliar << endl;
    a = atoi(auxiliar.c_str());
    cin >> b;
    unsigned int result = a%b;
    cout << result << endl;
}