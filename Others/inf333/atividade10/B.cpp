#include <iostream>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

struct TipoNodo {
	long long int gcd;
    long long int cont;
};



typedef TipoNodo T;
class SegTree {
public:
	SegTree(long long int n) {
		mxPos = n-1;
		t.resize(4*n);
	}

	T combine(T a, T b) {
	    T d;
        d.gcd = __gcd(a.gcd, b.gcd);
        d.cont = 0;
        if (d.gcd == a.gcd){
            d.cont += a.cont;
        }
        if (d.gcd == b.gcd){
            d.cont += b.cont;
        }
		
		return d;
	}

	T make(long long int x) {
		T d;
		d.gcd = x;
        d.cont = 1;
		return d;
	}
	T makeVazio() {
		T d;
		d.cont = 0;
        d.gcd = 0;
		return d;
	}
	//constroi a segTree com os elementos de a
	//inicialmente, tl=0, tr=n-1
	void build(vector<long long int> &a, long long int tl, long long int tr, long long int v) {
	    if (tl == tr) { //folha
	        t[v] = make(a[tl]); //adaptar
	    } else {
	        long long int tm = (tl + tr) / 2; //meio do segmento
	        //constroi nodos da esquerda ([tl,tm])
	        build(a, tl, tm, v*2); 
	        //constroi nodos da direita ([tm+1,tr])
	        build(a, tm+1, tr, v*2+1); 
	        //junta o resultado dos segmentos da esquerda e direita
	        //em geral, aqui é lugar mais "adaptado"
	        t[v] = combine(t[v*2] , t[v*2+1]); 
	    }
	}
	void build(vector<long long int> &a) {
		build(a,0,mxPos,1);
	}

	//consulta para encontrar a soma do long long intervalo [l,r]
	//procura no vértice v, representando os long long intervalos
	//[tl,tr] (na árvore)
	T query(long long int v, long long int tl, long long int tr, long long int l, long long int r) {
	    if (l > r) 
	        return makeVazio(); //adaptar, caso outro tipo de consulta
	    if (l == tl && r == tr) {
	        return t[v];
	    }
	    long long int tm = (tl + tr) / 2;

	    //chama SEMPRE para os dois lados
	    //mesmo se desnecessário --> ok (primeiro if)
	    //adaptar, caso outro tipo de consulta
	    return combine(query(v*2, tl, tm, l, min(r, tm)),
	            query(v*2+1, tm+1, tr, max(l, tm+1), r) );
	}
	T query(long long int l, long long int r) {
		return query(1,0,mxPos,l,r);
	}

	//nesse caso, new_val é long long inteiro
	void update(long long int v, long long int tl, long long int tr, long long int pos, long long int new_val) {
	    if (tl == tr) {
	        t[v] = make(new_val);
	    } else {
	        long long int tm = (tl + tr) / 2;
	        if (pos <= tm) //nodo está na esquerda?
	            update(v*2, tl, tm, pos, new_val);
	        else //nodo está na direita?
	            update(v*2+1, tm+1, tr, pos, new_val);

	        //atualiza raiz atual
	        //adaptar, caso outro tipo de consulta
	        t[v] = combine(t[v*2] , t[v*2+1]);
	    }
	}
	void update(long long int pos, long long int new_val) {
		update(1,0,mxPos,pos,new_val);
	}
private:
	vector<T> t;
	long long int mxPos;


};


int main() {
	long long int n;
    cin >> n;
    vector<long long int> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    SegTree st(n);
    st.build(v);
    int k;
    cin >> k;
    for (int i=0; i<k; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        auto teste = st.query(a,b);
        //cout << teste.gcd << " " << teste.cont << endl;
        long long int resp = (b-a)-teste.cont+1;
        cout << resp << endl;
    }

}