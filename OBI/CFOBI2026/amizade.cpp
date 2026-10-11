#include <bits/stdc++.h>
using namespace std;

vector<int>lazy;
vector<int> qtdmin;
vector<int> vmin;

void build(int u, int l, int r){
    if(l==r){
        vmin[u]=0;
        qtdmin[u]=1;
        return;
    }
    int meio=(l+r)/2;
    build(2*u, l, meio);
    build(2*u+1, meio+1, r);
    vmin[u]=0;
    qtdmin[u]=qtdmin[2*u]+qtdmin[2*u+1];
}
void push(int u, int l, int r){
    if(lazy[u]!=0){
        vmin[u]+=lazy[u];
        if(l!=r){
            lazy[2*u]+=lazy[u];
            lazy[2*u+1]+=lazy[u];
        }
        lazy[u]=0;
    }
}

void update(int u, int l, int r, int l1, int r1, int x){
    push(u, l, r);
    if(l>r1){
        return;
    }
    if(r<l1){
        return;
    }
    if(l>=l1){
        if(r<=r1){
            lazy[u]+=x;
            push(u, l, r);
            return;
        }
    }
    int meio=(l+r)/2;
    update(2*u, l, meio, l1, r1, x);
    update(2*u+1, meio+1, r, l1, r1, x);
    if(vmin[2*u]<vmin[2*u+1]){
        vmin[u]=vmin[2*u];
        qtdmin[u]=qtdmin[2*u];
    }
    if(vmin[2*u+1]<vmin[2*u]){
        vmin[u]=vmin[2*u+1];
        qtdmin[u]=qtdmin[2*u+1];
    
    }
    if(vmin[2*u]==vmin[2*u+1]){
        vmin[u]=vmin[2*u];
        qtdmin[u]=qtdmin[2*u]+qtdmin[2*u+1];
    }
}

long long query(int u, int l, int r, int l1, int r1){
    push(u, l, r);
    if(l>r1){
        return 0;
    }
    if(r<l1){
        return 0;

    }
    if(l>=l1){
        if(r<=r1){
            if(vmin[u]==0){
                return qtdmin[u];
            }
            return 0;
        }
    }
    int meio=(l+r)/2;
    long long esq=query(2*u, l, meio, l1, r1);
    long long dir=query(2*u+1, meio+1, r, l1, r1);
    return esq+dir;
}
long long varrer(int n, const vector<vector<pair<int, int>>>& inicio, const vector<vector<pair<int, int>>>& fim){
    vmin.assign(4*n+10, 0);
    qtdmin.assign(4*n+10, 0);
    lazy.assign(4*n+10, 0);
    build(1, 1, n);
    long long fotos=0;
    for(int l=1;l<=n;l++){
        for(const auto& r:inicio[l]){
            update(1, 1, n, r.first, r.second, 1);

        }
        fotos+=query(1,1,n,l, n);
        for(const auto& r: fim[l]){
            update(1,1,n,r.first, r.second, -1);
        }
    }
    return fotos;
}
int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> inicio(n+2);
    vector<vector<pair<int, int>>> fim(n+2);

    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        if(a>0){
            int esq=0, dir=n+1;
            for(int j=0;j<a;j++){
                int amigo;
                cin >> amigo;
                if(amigo<i){
                    if(amigo>esq){
                        esq=amigo;
                    }
                }else{
                    if(amigo<dir){
                        dir=amigo;
                    }
                }
            }
            int l1= esq+1, l2=i;
            int r1=i, r2=dir-1;
            if(l1<=l2){
                if(r1<=r2){
                    pair<int, int> r=make_pair(r1, r2);
                    inicio[l1].push_back(r);
                    fim[l2].push_back(r);
                }
            }
        }
    }
    long long fotos=varrer(n, inicio, fim);
    cout << fotos;
    return 0;
}
