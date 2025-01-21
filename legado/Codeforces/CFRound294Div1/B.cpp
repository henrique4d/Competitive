#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        string in;
        cin >> in;
        string resp = "";
        string A, B, C;

        if (in[0] == 'a' and in[1] == 'a' and in[in.size()-1] == 'a'){
            A = "a";
            B = in.substr(1, in.size()-2);
            C = "a";
        }

        if (in[0] == 'a' and in[1] == 'b' and in[in.size()-1] == 'a'){
            A = "a";
            B = in.substr(1, in.size()-2);
            C = "a";
        }

        if (in[0] == 'a' and in[1] == 'a' and in[in.size()-1] == 'b'){
            A = "a";
            B = "a";
            C = in.substr(2, in.size()-2);
        }


        if (in[0] == 'a' and in[1] == 'b' and in[in.size()-1] == 'b'){
            A = "a";
            B = in.substr(1, in.size()-2);
            C = "b";
        }


        if (in[0] == 'b' and in[1] == 'a' and in[in.size()-1] == 'a'){
            A = "b";
            B = "a";
            C = in.substr(2, in.size()-2);
        }

        if (in[0] == 'b' and in[1] == 'b' and in[in.size()-1] == 'a'){
            A = "b";
            B = in.substr(1, in.size()-2);
            C = "a";
        }

        if (in[0] == 'b' and in[1] == 'b' and in[in.size()-1] == 'b'){
            A = "b";
            B = in.substr(1, in.size()-2);
            C = "b";
        }


        if (in[0] == 'b' and in[1] == 'a' and in[in.size()-1] == 'b'){
            A = "b";
            B = in.substr(1, in.size()-2);
            C = "b";
        }

        cout << A << " " << B << " " << C << endl;

    }
}