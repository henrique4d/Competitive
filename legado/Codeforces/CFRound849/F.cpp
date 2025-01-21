// Program to show segment tree to demonstrate lazy
// propagation
#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int t[8*100000 * 5];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}
 
int getNum(int num, int n){
    //cout << num << " " << n << endl;
    for (int i=0; i<n; i++){
        int aux = 0;
        while (num > 0){
            aux += num%10;
            num/=10;
        }
        num = aux;
        if (num < 10) return num;
    }
    return num;
}
  
// Driver program to test above functions
int main()
{
    
    int z;
    cin >> z;
    int teste = 0;
    for (int l=0; l<z; l++){
       
        //memset(tree, 0, sizeof(tree));
        //memset(lazy, 0, sizeof(lazy));
        int n,q;
        cin >> n >> q;
        vector<int> v(n);
        for (int i=0; i<n; i++){
            cin >> v[i];
        }
        int arr[n] = {0};
        for (int i=0; i<n;i++){
            arr[i] = 0;
        }
        build(arr,1,0,n-1);
        

        //cout <<  getNum(v[199999],getSum(n,199999,199999)) << endl;
        // exit(0); 
        for (int i=0; i<q; i++){
            int cmd;
            cin >> cmd;
            //cout << cmd << endl;
            //cout << n << " " << q << " " << cmd << endl;
            int a,b;
            if (cmd == 1){
                cin >> a >> b;
                a--;
                b--;
                //cout << a << " " << b << endl;
                update(1, 0, n-1, a, b, 1);
                //updateRange(n,a,b,1);
            }
            if (cmd == 2){
                teste++;
                cin >> a;
                a--;
                //cout << "A value " << a << " " << v[a] << endl;
                
                //getNum(v[a],getSum(n,a,a));

                cout << getNum(v[a],get(1, 0, n-1, a)) << "\n";
                //cout <<"depois" << endl;
            }
            
        }
    }
 
}