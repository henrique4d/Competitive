
// A Naive recursive C++ program to find minimum number
// operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;
 
// Utility function to find minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }
 
int editDist(string str1, string str2, int m, int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;
 
    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;
 
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
 
    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1
           + min(editDist(str1, str2, m, n - 1), // Insert
                 editDist(str1, str2, m - 1, n), // Remove
                 editDist(str1, str2, m - 1,
                          n - 1) // Replace
             );
}
 
// Driver code
int main()
{
    int n;
    cin >> n;
    vector<double> pontuacao(5,0);
    vector<int> rodada(5);
    for (int i=0; i<n; i++){
        string original;
        cin >> original;
        //cout << original << "///" << endl;

        int menor = INT_MAX;
        for (int j=0; j<5; j++){
            string tentativa;
            cin >> tentativa;
            //cout << original << " " << tentativa << endl;
            rodada[j] = editDist(original, tentativa, original.size(), tentativa.size());
            menor = min(menor, rodada[j]);
        }

        for (int j=0; j<5;j++){
            //cout << rodada[j] << " " << menor << endl;
            if (rodada[j] == menor){
                if (menor == 0) pontuacao[j]++;
                else pontuacao[j] += 0.5;
            }
           
        }
        //cout << endl;
    }
    double best = 0;
    for (int i=0; i<5;i++){
        best = max(best, pontuacao[i]);
    }

    vector<int> melhores;
    for (int i=0; i<5; i++){
        if (pontuacao[i] == best){
            melhores.push_back(i);
        }
    }
    cout << fixed << setprecision(1) <<  best << endl;
    for (int i=0; i<melhores.size(); i++){
        cout << melhores[i]+1;
        if (i == melhores.size()-1) cout << endl;
        else cout << " ";
    }
    return 0;
}