
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    int top[3] = {0, 0, 0};

    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        if (a>=top[0]){
            top[2]=top[1];
            top[1]=top[0];
            top[0]=a;
        }else if(a>=top[1]){
            top[2]=top[1];
            top[1]=a;
        }else if(a>top[2]){
            top[2] = a;
        }
    }

    if(top[0] >= x){
        cout << 1 << "\n";
        return 0;
    }

    if(top[0] +top[1]-10 >= x){
        cout << 2 << "\n";
        return 0;
    }
    if(top[0] +top[1]+top[2]-20 >= x){
        cout << 3 << "\n";
        return 0;
    }

    cout << -1 << "\n";
    return 0;
}
