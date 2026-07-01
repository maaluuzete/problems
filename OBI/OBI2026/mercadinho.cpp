#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int jovens= 0;
    int tempomax= 0;

    for(int i=0; i<n; i++){
        int idade;
        cin >> idade;
        if(idade >= 60){
            // o tempo do idoso é igual aos jovens que estão à sua frente
            tempomax = max(tempomax, jovens);
        } else {
            // é um jovem, então acumula no contador
            jovens++;
        }
    }

    cout << tempomax << "\n";

    return 0;
}