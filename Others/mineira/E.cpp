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
// limit for array size
const int N = 1000000;
 
int n; // array size
 
// Max size of tree
node tree[2 * N];
 
// function to build the tree
void build( node arr[])
{
    // insert leaf nodes in tree
    for (int i=0; i<n; i++)   
        tree[n+i] = arr[i];
     
    // build the tree by calculating parents
    for (int i = n - 1; i > 0; --i){ 
        node primeiro = tree[i<<1];
        node segundo = tree[i<<1|1];

        if (segundo.index < primeiro.index){
            swap(primeiro, segundo);
        }

        tree[i].drawdown = max(primeiro.drawdown, segundo.drawdown);

        if (primeiro.porcentagem >= segundo.porcentagem){
            tree[i].percentualA = primeiro.percentualA;
            tree[i].percentualB = primeiro.percentualB;
            tree[i].porcentagem = primeiro.porcentagem;
        }
        else{
            tree[i].percentualA = segundo.percentualA;
            tree[i].percentualB = segundo.percentualB;
            tree[i].porcentagem = segundo.porcentagem;
        }


        //cout << primeiro.index << " " << segundo.index << " "<< primeiro.maior << " " << primeiro.menor << "            " << segundo.maior << " " << segundo.menor << endl;

        if (primeiro.maior - segundo.menor > tree[i].drawdown){
            tree[i].drawdown = primeiro.maior - segundo.menor;
        }
        if (1-((double)segundo.menor/primeiro.maior) > tree[i].porcentagem){
            tree[i].percentualA = primeiro.maior;
            tree[i].percentualB = segundo.menor;
            tree[i].porcentagem = 1-((double)segundo.menor/primeiro.maior);
        }

        tree[i].maior = max(primeiro.maior, segundo.maior);
        tree[i].menor = min(primeiro.menor, segundo.menor);
        tree[i].index = min(primeiro.index, segundo.index);
    }
}
// function to get sum on interval [l, r)
node queryDrawdown(int l, int r)
{
    node res;
    res.index = INT_MAX;
    res.drawdown = 0;
    res.percentualA = 0;
    res.percentualB = 0;
    res.maior = 0;
    res.menor = 0;
    res.porcentagem = 0;
     
    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1)
    {
        node primeiro, segundo;

        if (l&1 or r&1){
        cout << "l : " << l << " r : " << r << endl;
           if (l&1){
                    primeiro = res;
                    segundo = tree[l++];   
                    //res += tree[l++];
                    if (segundo.index < primeiro.index){
                        swap(primeiro, segundo);
                    }
                    if (res.index == INT_MAX){
                        res = primeiro;
                    }
                    else{
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
                        if (primeiro.maior - segundo.menor > res.drawdown){
                            res.drawdown = primeiro.maior - segundo.menor;
                        }
                        if (1-((double)segundo.menor/primeiro.maior) > res.porcentagem){
                            res.percentualA = primeiro.maior;
                            res.percentualB = segundo.menor;
                            res.porcentagem = 1-((double)segundo.menor/primeiro.maior);
                        }
                        cout << primeiro.index << " " << segundo.index << " " << primeiro.maior << " " << segundo.menor << " " << primeiro.maior - segundo.menor << endl;
                        cout << res.drawdown << endl;
                        res.maior = max(primeiro.maior, segundo.maior);
                        res.menor = min(primeiro.menor, segundo.menor);
                        res.index = min(primeiro.index, segundo.index);
                    }
                //cout << primeiro.index << " " << segundo.index << " "<< primeiro.maior << " " << primeiro.menor << "            " << segundo.maior << " " << segundo.menor << endl;
            }
            // if (r&1){
            //         primeiro = tree[--r];
            //         segundo = res;         
            //         //res += tree[--r];
            //         if (segundo.index < primeiro.index){
            //             swap(primeiro, segundo);
            //         }

            //         if (res.index == INT_MAX){
            //             res = primeiro;
            //         }else{
            //             res.drawdown = max(primeiro.drawdown, segundo.drawdown);

            //             if (primeiro.porcentagem >= segundo.porcentagem){
            //                 res.percentualA = primeiro.percentualA;
            //                 res.percentualB = primeiro.percentualB;
            //                 res.porcentagem = primeiro.porcentagem;
            //             }
            //             else{
            //                 res.percentualA = segundo.percentualA;
            //                 res.percentualB = segundo.percentualB;
            //                 res.porcentagem = segundo.porcentagem;
            //             }
            //             if (primeiro.maior - segundo.menor > res.drawdown){
            //                 res.drawdown = primeiro.maior - segundo.menor;
            //             }
            //             //cout << segundo.menor << " " << primeiro.maior << " " << (double)segundo.menor/primeiro.maior << endl;
            //             //cout << 1-((double)segundo.menor/primeiro.maior) << endl;
            //              cout << primeiro.index << " " << segundo.index << " " << primeiro.maior << " " << segundo.menor << " " << primeiro.maior - segundo.menor << endl;
            //             cout << res.drawdown << endl;
            //             if (1-((double)segundo.menor/primeiro.maior) > res.porcentagem){
            //                 res.percentualA = primeiro.maior;
            //                 res.percentualB = segundo.menor;
            //                 res.porcentagem = 1-((double)segundo.menor/primeiro.maior);
            //             }

            //             res.maior = max(primeiro.maior, segundo.maior);
            //             res.menor = min(primeiro.menor, segundo.menor);
            //             res.index = min(primeiro.index, segundo.index);
                
            //         }
            //         //cout << primeiro.index << " " << segundo.index << " "<< primeiro.maior << " " << primeiro.menor << "            " << segundo.maior << " " << segundo.menor << endl;
            //     }
            }

    }
     
    return res;
}


 
// driver program to test the above function
int main()
{
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

    build(arr);

    int k;
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
    return 0;
}