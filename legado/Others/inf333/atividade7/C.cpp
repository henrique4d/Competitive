
// The longest common subsequence in C++

#include <bits/stdc++.h>
using namespace std;

void lcsAlgo(string &S1, string &S2, int m, int n) {
  int LCS_table[m + 1][n + 1];


  // Building the mtrix in bottom-up way
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }

  int index = LCS_table[m][n];
  string lcsAlgo = "";
  for (int i=0; i<=index; i++){
      lcsAlgo.push_back(' ');
  }
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }
  
  // Printing the sub sequences
    cout << lcsAlgo.size()-1 << "\n";
}
  
/* Driver code */
int main() 
{ 
    string a,b;
    while (getline(cin,a)){
    
        getline(cin,b);
        //cout << a << " " << b << endl;
        lcsAlgo(a,b, a.size(), b.size());
        //cout << result << endl;
    }
    
} 
  
// This code is contributed by rathbhupendra