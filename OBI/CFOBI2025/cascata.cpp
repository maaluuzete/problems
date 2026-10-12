#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> g[100005];
int r[100005];
int apoio[100005];
bool quebrado[100005];
bool retirado[100005];
bool tentar[100005];

int main(void) {
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        apoio[b]++;
    }
    for(int i=0; i<k; i++){
        cin >> r[i];
        r[i]--;
        tentar[r[i]]=true;
    }
    for(int j=0; j<k; j++){
        int i=r[j];
        queue<int> q;
        if(tentar[i] && !quebrado[i]){
            q.push(i);
            retirado[i] = true;
            while(!q.empty()){
                int v=q.front();
                q.pop();
                for(int u : g[v]){
                    apoio[u]--;
                    if(apoio[u]==0 && !retirado[u]){
                        quebrado[u]=true;
                        q.push(u);
                    }
                }
            }
        }
    }
    
    int res=0;
    for(int i=0; i<n; i++){
        if(quebrado[i]){
          res++;
        }
  }
    cout << res << endl;
}
