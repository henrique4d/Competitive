// C++ program for range minimum
// query using segment tree
#include <bits/stdc++.h>
using namespace std;
 
long long int gcd(long long int a, long long int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

struct node{
    long long int maior, menor,drawdown, percentualA, percentualB;
    long double porcentagem;
    long long int index;
};


// A utility function to get minimum of two numbers
node minVal(node x, node y) {
    if (x.index == -1) return y;
    if (y.index == -1) return x;
    /*if (x.index == -1 or y.index == -1){
        cout << "ahhh" << endl;
    }*/
    node res;
    node primeiro = x;
    node segundo = y;

    if (segundo.index < primeiro.index){
        swap(primeiro, segundo);
    }

    res.drawdown = max(primeiro.drawdown, segundo.drawdown);

    if (primeiro.porcentagem >= segundo.porcentagem){
        res.percentualA = primeiro.percentualA;
        res.percentualB = primeiro.percentualB;
        res.porcentagem = primeiro.porcentagem;
    }
    else{
        res.percentualA = segundo.percentualA;
        res.percentualB = segundo.percentualB;
        res.porcentagem = segundo.porcentagem;
    }


    //cout << primeiro.index << " " << segundo.index << " "<< primeiro.maior << " " << primeiro.menor << "            " << segundo.maior << " " << segundo.menor << endl;

    if (primeiro.maior - segundo.menor > res.drawdown){
        res.drawdown = primeiro.maior - segundo.menor;
    }
    if (1-((double)segundo.menor/primeiro.maior) > res.porcentagem){
        res.percentualA = primeiro.maior;
        res.percentualB = segundo.menor;
        res.porcentagem = 1-((double)segundo.menor/primeiro.maior);
    }

    res.maior = max(primeiro.maior, segundo.maior);
    res.menor = min(primeiro.menor, segundo.menor);
    res.index = min(primeiro.index, segundo.index);
    return res;
}
 
// A utility function to get the
// middle index from corner indexes.
int getMid(int s, int e) { return s + (e -s)/2; }
 
/* A recursive function to get the
minimum value in a given range
of array indexes. The following
are parameters for this function.
 
    st --> Pointer to segment tree
    index --> Index of current node in the
           segment tree. Initially 0 is
           passed as root is always at index 0
    ss & se --> Starting and ending indexes
                of the segment represented
                by current node, i.e., st[index]
    qs & qe --> Starting and ending indexes of query range */
node RMQUtil(node *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part
    // of given range, then return
    // the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node
    // is outside the given range
    if (se < qs || ss > qe){
        node a;
        a.index = -1;
        return a;
    }
 
    // If a part of this segment
    // overlaps with the given range
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
// Return minimum of elements in range
// from index qs (query start) to
// qe (query end). It mainly uses RMQUtil()
node RMQ(node *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input";
        node a;
        return a;
    }
 
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs
// Segment Tree for array[ss..se].
// si is index of current node in segment tree st
node constructSTUtil(node arr[], int ss, int se,
                                node *st, int si)
{
    // If there is one element in array,
    // store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements,
    // then recur for left and right subtrees
    // and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                    constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
 
/* Function to construct segment tree
from given array. This function allocates
memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
node *constructST(node arr[], int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n)));
 
    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;
 
    node *st = new node[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
 
// Driver program to test above functions
int main()
{       
        int n;
        cin >> n;
        node arr[n];
        for (int i=0; i<n; i++){
        cin >> arr[i].maior;
        arr[i].menor = arr[i].maior;
        arr[i].percentualA = arr[i].maior;
        arr[i].percentualB = arr[i].maior;
        arr[i].drawdown = 0;
        arr[i].porcentagem = 0;
        arr[i].index = i;
        }

 
    // Build segment tree from given array
        node *st = constructST(arr, n);

        //int qs = 1; // Starting index of query range
        //int qe = 5; // Ending index of query range
 
    // Print minimum value in arr[qs..qe]
      //cout<<"Minimum of values in range ["<<qs<<", "<<qe<<"] "<<
      //"is = "<<RMQ(st, n, qs, qe).drawdown<<endl;
 
    int k;
    cin >> k;

    for (int i=0; i<k; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        node resultdraw = RMQ(st,n, a,b);

        //cout << resultdraw.drawdown << " " << resultporcent.percentualA << " " << resultporcent.percentualB << endl;
        long long int A = resultdraw.percentualA - resultdraw.percentualB;
        long long int B = resultdraw.percentualA;

        //cout << A << " " << B << << " " << gcd(A,B) endl;
        long long int divisor = gcd(A,B);
        
        A = A/divisor;

        B = B/divisor;

        if (resultdraw.porcentagem < 0){
            A = 0;
            B = 1;
        }

        cout << resultdraw.drawdown << " " << A << " " << B << endl;

    

    }
      return 0;
}

/*    int k;
    cin >> k;

    for (int i=0; i<k; i++){
        int a,b;
        cin >> a >> b;
        a--;
        node resultdraw = queryDrawdown(a,b);

        //cout << resultdraw.drawdown << " " << resultporcent.percentualA << " " << resultporcent.percentualB << endl;
        long long int A = resultdraw.percentualA - resultdraw.percentualB;
        long long int B = resultdraw.percentualA;

        //cout << A << " " << B << << " " << gcd(A,B) endl;
        long long int divisor = gcd(A,B);
        
        A = A/divisor;

        B = B/divisor;

        if (resultdraw.porcentagem < 0){
            A = 0;
            B = 1;
        }

        cout << resultdraw.drawdown << " " << A << " " << B << endl;

    

    }
    return 0;*/
 
// This code is contributed by rathbhupendra