#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
int comp[100005];
bool visited[100005];

void bfs(int no, int c){
    queue<int> q;
    q.push(no);
    visited[no]=true;
    comp[no]=c;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v]=true;
                comp[v]=c;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int nc=0;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            bfs(i, nc);
            nc++;
        }
    }

    int q;
    cin >> q;

    while (q--){
        int k;
        cin >> k;
        vector<int> rotas(k);
        for (int i=0; i<k; i++){
           cin >> rotas[i];
        }
        int voos=0;
        for (int i=0; i+1<k; i++){
            if (comp[rotas[i]] != comp[rotas[i+1]]){
                voos++;
            }
        }
        cout << voos << "\n";
    }

    return 0;
}
