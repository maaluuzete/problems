#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    
    int x[n], p[n];
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> p[i];

    pair<int, int> moedas[n];
    for(int i = 0; i < n; i++) {
        moedas[i].first = x[i] % b;
        moedas[i].second = p[i];
    }

    sort(moedas, moedas + n);

    int resposta = 0;
    int soma_atual = 0;
    int resto_atual = -1;

    for(int i = 0; i < n; i++) {
        if (moedas[i].first == resto_atual) {
            soma_atual += moedas[i].second;
        }else{
            resposta = max(resposta, soma_atual);
            resto_atual = moedas[i].first;
            soma_atual = moedas[i].second;
        }
    }
    
    resposta = max(resposta, soma_atual);
    cout << resposta << '\n';
}
