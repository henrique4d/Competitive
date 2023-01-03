#include <bits/stdc++.h>
using namespace std;


void dfs(int pos, vector<vector<int>> &tree, bool* visited, int dist_atual, int dist_maxima, priority_queue<int>&possibilities, bool* inPq){
    
    if (dist_atual > dist_maxima) return;
    if (visited[pos]) return;
    if (dist_atual == 0) visited[pos] = true;
    
    if (!inPq[pos])
        possibilities.push(-1*pos);
    
    inPq[pos] = true;
    
    for (auto it = tree[pos].begin(); it!=tree[pos].end(); ++it){
        if (!visited[*it])
            dfs(*it, tree, visited, dist_atual + 1, dist_maxima, possibilities, inPq);
    }
}



int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> tree(n);

    for (int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        a-=1;
        b-=1;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    priority_queue<int> possibilities;

    bool visited[n];
    bool inPq[n];
    memset(visited,false, sizeof(visited));
    dfs(0, tree, visited, 0, k, possibilities, inPq);
        
    vector<int> final_path;
    final_path.push_back(0);

    while (!possibilities.empty()){
        
        int pos = -1*possibilities.top();
        possibilities.pop();
        
        if (!visited[pos]){
        final_path.push_back(pos);
        dfs(pos, tree, visited, 0, k, possibilities, inPq);
        }
    }

    for (int i=0; i<final_path.size(); i++){
        cout << final_path[i]+1 << " ";
    }
    cout << endl;
    


}