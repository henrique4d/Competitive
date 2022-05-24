#include <bits/stdc++.h>
using namespace std;

void fill (int x, int y, const vector<string> &matrix, int &val_atual, vector<pair<int,int>> &done){
    if (x <0 or y<0 or x>=matrix[0].size() or y>=matrix[0].size()) return;
    for (int i=0; i<done.size(); i++){
        if (done[i].first == x and done[i].second == y) return;
    }
    if (matrix[x][y] == 'W'){
        val_atual++;
        done.push_back(make_pair(x,y));
        fill(x+1, y, matrix, val_atual, done);
        fill(x+1, y+1, matrix, val_atual, done);
        fill(x+1, y-1, matrix, val_atual, done);

        fill(x, y+1, matrix, val_atual, done);
        fill(x, y-1, matrix, val_atual, done);

        fill(x-1, y, matrix, val_atual, done);
        fill(x-1, y+1, matrix, val_atual, done);
        fill(x-1, y-1, matrix, val_atual, done);

    }

}


int main(){
    int t;
    cin >> t;
    bool processing = false;
    vector<string> matrix;
    string in;   

    vector<vector<int>> auxiliar;

    for (int l=0; l<t;l++){
        while (cin >> in){
            if (!isdigit(in[0])){
                if (processing){
                    matrix.clear();
                    processing = false;
                    cout << "\n";
                    matrix.push_back(in);
                    break;
                }
                matrix.push_back(in);
            }
            else{
                if (!processing){
                    processing = true;
                    auxiliar.clear();
                    for (int i=0; i<matrix.size(); i++){
                        vector<int> aux2;
                        for (int j=0; j<matrix[i].size(); j++){
                            vector<pair<int,int>> done;  
                            int result = 0;
                            fill(i,j, matrix, result,done);
                            aux2.push_back(result);
                        }
                        auxiliar.push_back(aux2);
                    }
                }
                int result = 0;
                int x,y;
                x = atoi(in.c_str());
                cin >> y;
                cout << auxiliar[x-1][y-1] << "\n";
            }
        }
    }
}