#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> lazy;

void pull(int no, int shift, int k){
    if (shift==0){
      return;
    }
    vector<int> proximo(k+2, -1);
    for (int i=0; i+shift < k+2; i++){
        proximo[i + shift] = tree[no][i];
    }
    tree[no] = move(proximo);
    lazy[no] += shift;
}

void push(int no, int k){
    if (lazy[no]>0){
        pull(2*no, lazy[no], k);
        pull(2*no+1, lazy[no], k);
        lazy[no] = 0;
    }
}

void updateshift(int no, int inicio, int fim, int l, int r, int k){
    if (l>r || l>fim || r<inicio){
      return;
    }
    if(l<=inicio && fim<=r){
        pull(no, 1, k);
        return;
    }
    push(no, k);
    int meio=(inicio+fim)/2;
    updateshift(2 *no, inicio, meio, l, r, k);
    updateshift(2 *no+1, meio+1, fim, l, r, k);
    
    for (int i=0; i<= k; i++){
        tree[no][i] = max(tree[2*no][i], tree[2*no+1][i]);
    }
}

void updatepoint(int no, int inicio, int fim, int pos, const vector<int>& valores, int k){
    if (inicio==fim){
        for (int i=0; i<=k; i++){
            if(valores[i]>tree[no][i]){
                tree[no][i]=valores[i];
            }
        }
        return;
    }
    push(no, k);
    int meio=(inicio+fim) /2;
    if (pos<=meio){
        updatepoint(2*no, inicio, meio, pos, valores, k);
    }else{
        updatepoint(2*no+1, meio+1, fim, pos, valores, k);
    }
    
    for (int i=0; i<= k; i++){
        tree[no][i] = max(tree[2*no][i], tree[2*no+1][i]);
    }
}

vector<int> query(int no, int inicio, int fim, int l, int r, int k){
    if (l > r || l > fim || r < inicio){
        return vector<int>(k+2, -1);
    }
    if (l <= inicio && fim <= r){
        return tree[no];
    }
    push(no, k);
    int meio=(inicio+fim)/2;
    vector<int> esquerda=query(2*no, inicio, meio, l, r, k);
    vector<int> direita=query(2*no+1, meio+1, fim, l, r, k);
    
    vector<int> resconsulta(k+2);
    for (int i = 0; i< k+2; i++){
        resconsulta[i] = max(esquerda[i], direita[i]);
    }
    return resconsulta;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<int> lis;
    for(int x:v){
        auto pos=lower_bound(lis.begin(), lis.end(), x);
        if(pos == lis.end()){
            lis.push_back(x);
        }else{
            *pos=x;
        }
    }

    if (k>=n-(int)lis.size()){
        cout << lis.size() << "\n";
        return 0;
    }

    vector<int> v2=v;
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    int m=v2.size();

    vector<int> cv(n);
    for(int i=0; i<n; i++){
        cv[i] =lower_bound(v2.begin(), v2.end(), v[i]) -v2.begin()+1;
    }
    vector<int> r(n, 0);
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (cv[j] > cv[i]){
                r[i]++;
            }
        }
    }

    int tamtree=4*(m+2);
    tree.assign(tamtree, vector<int>(k+2, -1));
    lazy.assign(tamtree, 0);

    int res=0;

    for (int i=0; i<n; i++){
        int custo=0;
        for(int j=0; j<i; j++){
            if (cv[j] > cv[i]){
                custo++;
            }
        }

        vector<int> dp(k+2, -1);
        if (custo<=k){
            dp[custo]=1;
        }

        vector<int> q = query(1, 1, m, 1, cv[i]-1, k);
        for (int i=0; i<= k; i++){
            if (q[i]!=-1 && q[i]+1>dp[i]){
                dp[i]=q[i]+1;
            }
        }

        for (int j= 0; j<= k-r[i]; j++){
            if (dp[j] > res) {
                res = dp[j];
            }
        }

        updatepoint(1, 1, m, cv[i], dp, k);

        if (cv[i]>1){
            updateshift(1, 1, m, 1, cv[i]-1, k);
        }
    }

    cout << res;

    return 0;
}
