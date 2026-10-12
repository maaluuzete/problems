#include <iostream>

using namespace std;

const int MAXN = 100005;
long long altura[MAXN], fotos[MAXN], resposta[MAXN];
long long somaponderada[MAXN], alturav[MAXN], somaacumulada[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, topo=0;
    cin >> n;

    for(int i=0; i<n; i++){
      cin >> altura[i];
    }
    altura[n] = 1e9;
    for(int i=0; i<n; i++){
      cin >> fotos[i];
    }

    alturav[0] = 1e9;

    for(int i=n-1; i>=0; i--){
        int p=topo-fotos[i];
        if(topo<fotos[i]){
            resposta[i]=-1;
        }else{
            resposta[i]=somaponderada[topo]-somaponderada[p]-p*(somaacumulada[topo]-somaacumulada[p]);
        }
        while(altura[i] >= alturav[topo]){
            topo--;
        }
        topo++;
        somaponderada[topo] = somaponderada[topo-1] + topo*altura[i];
        alturav[topo] = altura[i];
        somaacumulada[topo] = altura[i]+somaacumulada[topo-1];
    }

    for(int i=0; i<n; i++){
        cout << resposta[i] <<  " ";
    }
    cout << "\n";

    return 0;
}
