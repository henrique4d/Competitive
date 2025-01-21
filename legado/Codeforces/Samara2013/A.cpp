#include <bits/stdc++.h>
using namespace std;
bool compare1(vector<int> &a, vector<int> &b){
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] > b[0];
}

bool compare2(vector<int> &a, vector<int> &b){
    if (a[1] == b[1]) return a[0] > b[0];
    return a[1] > b[1];
}

bool compare3(vector<int> &a, vector<int> &b){
    return a[0]+a[1] > b[0]+b[1];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> vOrig(n,vector<int>(3));
    vector<vector<int>> v1(n,vector<int>(3));
    vector<vector<int>> v2(n,vector<int>(3));
    vector<vector<int>> v3(n,vector<int>(3));
    
    for (int i=0; i<n ;i++){
        cin >> vOrig[i][0];
        cin >> vOrig[i][1];
        cin >> vOrig[i][2];

        v1[i] = vOrig[i];
        
        sort(vOrig[i].begin(), vOrig[i].end(), greater<int>());
        sort(v1[i].begin(), v1[i].end());

        v2[i] = v1[i];
        v3[i] = v1[i];
    }
    sort(v1.begin(), v1.end(), compare1);
    sort(v2.begin(), v2.end(), compare2);
    sort(v3.begin(), v3.end(), compare3);

    vector<int> resp;

    for (int i=0; i<n; i++){
        // cout << "comparando a posicao " << i << " com :\n";
        // cout << vOrig[i][1] << " " << vOrig[i][0] << endl;
        
        // cout << v1[i][0] << " " << v1[i][1] << endl;
        // cout << v2[i][0] << " " << v2[i][1] << endl;
        // cout << v3[i][0] << " " << v3[i][1] << endl;
        

        if (vOrig[i][1] < v1[0][0] or vOrig[i][0] < v1[0][1]) continue;       
        if (vOrig[i][1] < v2[0][0] or vOrig[i][0] < v2[0][1]) continue;       
        if (vOrig[i][1] < v3[0][0] or vOrig[i][0] < v3[0][1]) continue;       

        resp.push_back(i+1);
    }

    printf("%d\n", (int)resp.size());

    for (int i=0; i<resp.size(); i++){
        if (i!=0) printf(" ");
        printf("%d", resp[i]);
    }
    printf("\n");

    
}