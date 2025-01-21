#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l = 0; l<z; l++){
        long long int n,k,x,y;
        cin >> n >> k >> x >> y;    
        vector<long long int> A;
        vector<long long int> B;
        A.reserve(n);
        B.reserve(n);

        for (int i=0; i<n; i++){
            char tipo;
            long long int value;
            cin >> tipo >> value;
            if (tipo == 'A') A.push_back(value);
            else B.push_back(value);
        }
        A.resize(n,-100000000);
        B.resize(n,-100000000);

        sort(A.begin(), A.end(), greater<long long int>());
        sort(B.begin(), B.end(), greater<long long int>());

        
        long long int indexA = 0;
        long long int indexB = 0;
        long long int final_value = 0;

        for (; indexA < k; indexA++){
            final_value += A[indexA];
        }

        for(; indexB <k; indexB++){
            final_value += B[indexB];
        }

        while (indexA < A.size() and indexB-1 >=0 and A[indexA] - x > B[indexB-1]){
            final_value += A[indexA] - x - B[indexB-1];
            indexA++;
            indexB--;
        }
       
        while (indexB < B.size() and indexA-1 >=0 and B[indexB] - y > A[indexA-1]){
            final_value += B[indexB] - y - A[indexA-1];
            indexB++;
            indexA--;
        }

        cout << final_value << endl;
    }
}