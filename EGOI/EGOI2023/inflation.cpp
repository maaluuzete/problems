#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<long long, long long> frequencia;
    long long soma=0;

    for(int i=0; i<n; i++){
        long long p;
        cin >> p;
        frequencia[p]++;
        soma+= p;
    }

    int q;
    cin >> q;

    long long inflacao=0;

    while (q--){
        string s;
        cin >> s;

        if(s == "INFLATION"){
            long long x;
            cin >> x;
            inflacao+=x;
            soma+= (long long)n*x;
        }else if (s == "SET"){
            long long x, y;
            cin >> x >> y;

            long long bantg = x-inflacao;
            long long bnova=y-inflacao;

            if(bantg != bnova){
                auto posicao = frequencia.find(bantg);
                if (posicao != frequencia.end()){
                    long long quant= posicao->second;
                    frequencia.erase(posicao);
                    frequencia[bnova]+=quant;
                    soma+=quant*(y-x);
                }
            }
        }
        cout << soma<< "\n";
    }

    return 0;
}