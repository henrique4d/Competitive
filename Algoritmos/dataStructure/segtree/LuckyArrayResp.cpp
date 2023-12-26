// by caonima
// hehe
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+10;
int num[MAX<<2],Min[MAX<<2] ,col[MAX<<2],cnt[MAX<<2];
int a[MAX],Luck_num[MAX],cur=0;
int is_luck[MAX];
char op[10];
void dfs(int u) {
    if(u>444444) return ;
    is_luck[u]=true;
    Luck_num[cur++]=u;

    dfs(u*10+4);
    dfs(u*10+7);
    return ;
}
int check(int x) {
    for(int i=0;i<cur;i++) {
        if(x<Luck_num[i]) return Luck_num[i]-x;
    }
    return 0;
}
void push_up(int o) {   //funcao que atualiza o elemento de acordo com os filhos
    cnt[o]=cnt[o<<1]+cnt[o<<1|1];   //cont[o] = cont[2*o] + cont[2*o + 1] ( entender o pq raios isso funciona )
    Min[o]=min(Min[o<<1],Min[o<<1|1]);  //Min[o] = min(Min[2*o], Min[2*o+1])
}

//cria uma segment tree com cada intervalo salvando o numero de lucky numbers do intervalo
//e a menor distancia de um elemento pro proximo lucky number
void build(int L,int R,int o) {
    if(L==R) {
        num[o]=a[L]; col[o]=0;
        if(is_luck[a[L]]) cnt[o]=1;
        else cnt[o]=0;
        Min[o]=check(a[L]);
        return ;
    }
    int mid=(L+R)>>1;
    build(L,mid,o<<1);
    build(mid+1,R,o<<1|1);
    push_up(o);
}


void push_down(int o,int m) {
    if(col[o]) {
        col[o<<1]+=col[o]; col[o<<1|1]+=col[o];
        Min[o<<1]-=col[o<<1]; Min[o<<1|1]-=col[o<<1|1];
        cnt[o<<1]=cnt[o<<1|1]=0;
        col[o]=0;
    }
}

int Query(int L,int R,int o,int ls,int rs) {
    if(ls<=L&&rs>=R) {
        return cnt[o];
    }
    push_down(o,R-L+1);//printf("s");
    int mid=(R+L)>>1;
    int cnt=0;
    if(ls<=mid) cnt+=Query(L,mid,o<<1,ls,rs);
    if(rs>mid) cnt+=Query(mid+1,R,o<<1|1,ls,rs);
    push_up(o);
    return cnt;
}

void Update(int L,int R,int o,int ls,int rs,int val) {
    if(ls<=L&&rs>=R) {
        if(L==R) {
            num[o]+=col[o]+val;
            col[o]=0;
        //  printf("%d\n",num[o]);
            if(is_luck[num[o]]) cnt[o]=1;
            else cnt[o]=0;
            Min[o]=check(num[o]);
            return ;
        }
        if(col[o]+val<Min[o]) { // se isso acontecer, eu nao consegui fazer nenhum elemento chegar no proximo lucky number ( logo nao tem nenhum... make sense???? maybe )
            Min[o]-=(col[o]+val);
            col[o]+=val;
            cnt[o]=0;
            return ;
        }
    }

    push_down(o,R-L+1);
    int mid=(R+L)>>1;
    if(ls<=mid)  Update(L,mid,o<<1,ls,rs,val);
    if(rs>mid) Update(mid+1,R,o<<1|1,ls,rs,val);
    push_up(o);
    return ;
}

int main() {
    int n,m,ls,rs,v;
    dfs(4); dfs(7); //seta todos os lucky numbers
    sort(Luck_num,Luck_num+cur);
    while(scanf("%d %d",&n,&m)==2) {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);    //le os valores
        build(1,n,1);   //cria a segment tree
        for(int i=1;i<=m;i++) {
            scanf("%s",op);
            if(op[0]=='c') {
                scanf("%d %d",&ls,&rs);
                int ans=Query(1,n,1,ls,rs);
                printf("%d\n",ans);
            }
            else {
                scanf("%d %d %d",&ls,&rs,&v);
                Update(1,n,1,ls,rs,v);
            }
        }
    }
    return 0;
}