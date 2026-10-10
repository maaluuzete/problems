#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i=0; i<n; i++){
        cin >> b[i];
    }
    vector<vector<int>> ga(d);
    vector<vector<int>> gb(d);

    for(int i=0; i<n; i++){
        ga[i%d].push_back(a[i]);
        gb[i%d].push_back(b[i]);
    }

    bool possivel=true;
    for (int i=0; i<d; i++) {
        sort(ga[i].begin(), ga[i].end());
        sort(gb[i].begin(), gb[i].end());
        if (ga[i]!=gb[i]){
            possivel = false;
            break;
        }
    }

    if(possivel){
        cout << "S\n";
    }else{
        cout << "N\n";
    }

    return 0;
}
