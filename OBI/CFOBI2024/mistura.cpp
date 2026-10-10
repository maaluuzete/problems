#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    long long totalsub = n*(n+1)/2;
    long long invalidas=0;

    if(k==2){
        long long atual = 1;
        for (int i=1; i<n; i++){
            if (a[i] == a[i-1]){
                atual++;
            }else{
                invalidas+=atual*(atual+1)/2;
                atual=1;
            }
        }
        invalidas+=atual*(atual+1)/2;
    }else{
        int esquerda = 0;
        vector<int> contador(n+1, 0);
        int distintos = 0;

        for (int direita=0; direita<n; direita++){
            if (contador[a[direita]] == 0){
                distintos++;
            }
            contador[a[direita]]++;

            while (distintos >= k) {
                contador[a[esquerda]]--;
                if (contador[a[esquerda]] == 0){
                    distintos--;
                }
                esquerda++;
            }
            invalidas+=(direita-esquerda+1);
        }
    }

    cout << totalsub-invalidas;

    return 0;
}