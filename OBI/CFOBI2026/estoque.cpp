#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> h(n);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    for(int i=1;i<n;i++){
        if(h[i]>h[i-1]+1){
            h[i]=h[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(h[i]>h[i+1]+1){
            h[i]=h[i+1]+1;
        }
    }
    long long moedas=0;
    for(int i=0;i<n;i++){
        moedas+=h[i];
    }
    cout << moedas;
    return 0;
}
