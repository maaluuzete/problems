#include <bits/stdc++.h>

using namespace std;

int proximo_numero(int n){
    int d[4];
    d[0]=(n/1000)%10;
    d[1]=(n/100)%10;
    d[2]=(n/10)%10;
    d[3]=n%10;
    
    // ordena os 4 dígitos em ordem crescente
    sort(d, d+4);

    int x1=d[0]*1000 +d[1]*100 + d[2]*10 + d[3];
    int x2=d[3]*1000 +d[2]*100 + d[1]*10 + d[0];
    
    return x2-x1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> torre;
    set<int> vistos;
    torre.push_back(n);
    vistos.insert(n);

    while (true){
        int atual=torre.back();
        int proximo=proximo_numero(atual);
        
        // se o número já foi visto na torre, paramos a simulação
        if(vistos.count(proximo)){
            break;
        }
        
        // se for novo, adiciona no topo e continua
        torre.push_back(proximo);
        vistos.insert(proximo);
    }
    for (int num : torre){
        cout << num << "\n";
    }

    return 0;
}