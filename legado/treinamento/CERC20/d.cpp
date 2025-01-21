#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = 150;
bool start[MAX][MAX][5];
int comp[MAX*MAX*5];
vector<int> adj[MAX*MAX*10];

int n;

int convert(int i, int j, char tipo){
    int resp = 0;
    if (tipo == 'R') resp = 0;
    else if (tipo == 'Q') resp = 1;
    else if (tipo == 'B') resp = 2;
    else if (tipo == 'N') resp = 3;
    else if (tipo == 'K') resp = 4;

    resp += i*5 + j*5*n;
}



int main(){
    cin >> n;
    char tipo;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> tipo;
            if (tipo == 'R') start[i][j][0] = true;
            else if (tipo == 'Q') start[i][j][1] = true;
            else if (tipo == 'B') start[i][j][2] = true;
            else if (tipo == 'N') start[i][j][3] = true;
            else if (tipo == 'K') start[i][j][4] = true;
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            //caso de ser R
            for (int k=1; k<n; k++){
                if (i+k < n) adj[convert(i,j,0)].push_back(convert(i+k,j,0));

                if (i-k >=0 ) adj[convert(i,j,0)].push_back(convert(i-k,j,0));

                if (j+k < n) adj[convert(i,j,0)].push_back(convert(i,j+k,0));

                if (j-k >= 0) adj[convert(i,j,0)].push_back(convert(i,j-k,0));
            }

            //caso de ser Q
            for (int k=1; k<n; k++){
                if (i+k < n) adj[convert(i,j,1)].push_back(convert(i+k,j,1));
                if (i-k >=0 ) adj[convert(i,j,1)].push_back(convert(i-k,j,1));
                if (j+k < n) adj[convert(i,j,1)].push_back(convert(i,j+k,1));
                if (j-k >= 0) adj[convert(i,j,1)].push_back(convert(i,j-k,1));
                if (i-k >= 0 and j-k >= 0) adj[convert(i,j,1)].push_back(convert(i-k,j-k,1));
                if (i+k < n and j-k >=0) adj[convert(i,j,1)].push_back(convert(i+k,j-k,1));
                if (i-k >=0 and j+k <n) adj[convert(i,j,1)].push_back(convert(i-k,j+k,1));
                if (i+k<n and j+k < n) adj[convert(i,j,1)].push_back(convert(i+k,j+k,1));
            }

            //caso de se B
            for (int k=1; k<n; k++){
                if (i-k >= 0 and j-k >= 0) adj[convert(i,j,2)].push_back(convert(i-k,j-k,2));
                if (i+k < n and j-k >=0) adj[convert(i,j,2)].push_back(convert(i+k,j-k,2));
                if (i-k >=0 and j+k <n) adj[convert(i,j,2)].push_back(convert(i-k,j+k,2));
                if (i+k<n and j+k < n) adj[convert(i,j,2)].push_back(convert(i+k,j+k,2));
            }

            //caso de ser N
            if (i-2 >= 0 and j-1 >= 0) adj[convert(i,j,3)].push_back(convert(i-2,j-1,3));
            if (i-2 >= 0 and j+1 < n) adj[convert(i,j,3)].push_back(convert(i-2,j+1,3));
            
            if (i+2 < n and j-1 >= 0) adj[convert(i,j,3)].push_back(convert(i+2,j-1,3));
            if (i+2 < 0 and j+1 < n) adj[convert(i,j,3)].push_back(convert(i+2,j+1,3));
            
            if (i-1 >= 0 and j-2 >= 0) adj[convert(i,j,3)].push_back(convert(i-1,j-2,3));
            if (i-1 >= 0 and j+2 < n) adj[convert(i,j,3)].push_back(convert(i-1,j+2,3));
            
            if (i+1 < n and j-2 >= 0) adj[convert(i,j,3)].push_back(convert(i+1,j-2,3));
            if (i+1 < 0 and j+2 < n) adj[convert(i,j,3)].push_back(convert(i+1,j+2,3));
   

            for (int k=1; k<=1; k++){
                if (i+k < n) adj[convert(i,j,1)].push_back(convert(i+k,j,4));
                if (i-k >=0 ) adj[convert(i,j,1)].push_back(convert(i-k,j,4));
                if (j+k < n) adj[convert(i,j,1)].push_back(convert(i,j+k,4));
                if (j-k >= 0) adj[convert(i,j,1)].push_back(convert(i,j-k,4));
                if (i-k >= 0 and j-k >= 0) adj[convert(i,j,1)].push_back(convert(i-k,j-k,4));
                if (i+k < n and j-k >=0) adj[convert(i,j,1)].push_back(convert(i+k,j-k,4));
                if (i-k >=0 and j+k <n) adj[convert(i,j,1)].push_back(convert(i-k,j+k,4));
                if (i+k<n and j+k < n) adj[convert(i,j,1)].push_back(convert(i+k,j+k,4));
            }

        }
    }
}