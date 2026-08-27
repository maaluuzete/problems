#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long lint;
const int MAX=810;
int mat[MAX][MAX],pre[MAX][MAX],dp[MAX][MAX];
stack<pii> pilha;
lint areamax;

void atualizapilha(int h,int l){
    int qtd=0;
    while(!pilha.empty()&&h<pilha.top().first){
        qtd+=pilha.top().second;
        areamax=max(areamax,(lint)qtd*pilha.top().first);
        pilha.pop();
    }
    pilha.push({h,qtd+l});
}

void precalcula(int n,int m){
    for(int i=0;i<n;i++){
        mat[i][m]=INT_MIN;
        for(int j=m-1;j>=0;j--){
            if(mat[i][j]<mat[i][j+1]){
                pre[i][j]=pre[i][j+1]+1;
            }else{
                pre[i][j]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        mat[n][i]=INT_MAX;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=lower_bound(mat[i]+j,mat[i]+j+pre[i][j],mat[i+1][j])-(mat[i]+j);
        }
    }
}

void calculaarea(int n,int m){
    areamax=0;
    for(int j=0;j<m;j++){
        pilha=stack<pii>();
        for(int i=0;i<n;i++){
            atualizapilha(pre[i][j],1);
            atualizapilha(dp[i][j],0);
        }
        atualizapilha(0,0);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            pre[i][j]=0;
        }
    }
    precalcula(n,m);
    calculaarea(n,m);
    cout<<areamax;
    return 0;
}
