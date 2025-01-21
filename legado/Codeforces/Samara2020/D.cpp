#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<char,pair<int,int>> &A,const pair<char,pair<int,int>> &B ){
    return A.first < B.first;
}
int main(){
    int n,m;
    cin >> n >> m;

    list<pair<char,int>> neighbors[n];
    int from;
    int to;
    char label;
    for (int i=0; i<m; i++){
        cin >> from >> to >> label;
        from--;
        to--;
        neighbors[from].push_back({label, to});
        neighbors[to].push_back({label, from});
    }
    for (int i=0; i<n; i++){
        neighbors[i].sort();
    }

    vector<bool> visited(n, false);
    pair<int, char> path[n];
    deque<pair<char,pair<int,int>>> q;

    visited[n-1] = true;

    int posAnterior = n-1;
    int pos = n-1;
    for (auto it = neighbors[n-1].begin(); it!= neighbors[n-1].end(); it++){
        q.push_back({it->first, {it->second, n-1}});
        path[it->second] = {n-1, it->first};
        
        if (it->second == 0) goto here;
    }
    while (true){
        int tam = q.size();

        stable_sort(q.begin(), q.end(), compare);       
        while (tam--){
            int sairDe = q.front().second.first;
            int chegarNe = q.front().second.second;
            char label = q.front().first;
 
            pos = q.front().second.first;           
            
            
            q.pop_front();
            if (visited[pos]) continue;
            visited[pos] = true;
            path[sairDe] = {chegarNe, label};
            
            if (pos == 0) goto here;
          
            for (auto it = neighbors[pos].begin(); it!= neighbors[pos].end(); it++){
                q.push_back({it->first, {it->second, pos}});
            }

        }       
    }

    here:

    vector<int> resp;
    string resp2 = "";
    
    resp.push_back(0);

    int posatual = 0;

    while (posatual!=n-1){
        resp.push_back(path[posatual].first);
        resp2.push_back(path[posatual].second);

        posatual = path[posatual].first; 
    }
    
    cout << resp2.size() << endl;

    for (int i=0; i<resp.size(); i++){
        if (i!=0) cout << " ";
        cout << resp[i]+1;
    }
    cout << endl;
    cout << resp2 << endl;

}