#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, f;
    cin >> n >> f;
    vector<int> e(n);
    for(int i=0; i<n; i++){
        cin >> e[i];
    }

    vector<int> p(f);
    for(int i=0; i<f; i++){
        cin >> p[i];
    }

    vector<int> b(f);
    for (int i=0; i<f; i++){
        cin >> b[i];
    }

    sort(e.begin(), e.end());

    vector<pair<int, int>> fadas(f);
    for (int i=0; i<f; i++){
        fadas[i] = {p[i], b[i]};
    }
    
    sort(fadas.begin(), fadas.end());

    int derrotados=0;

    for (int i=0; i<n; i++){
        int escolhida=-1;
        int menorpoder=2e9;

        for (int j=0; j<f; j++){
            if (fadas[j].second>0 && fadas[j].first>=e[i] && fadas[j].first<menorpoder){
                menorpoder=fadas[j].first;
                escolhida=j;
            }
        }

        if (escolhida!=-1){
            fadas[escolhida].second--;
            derrotados++;
        }
    }

    cout << derrotados;

    return 0;
}