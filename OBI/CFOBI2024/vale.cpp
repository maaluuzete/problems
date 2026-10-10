#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n>=100){
        cout << n + 15 << "\n";
    } else {
        cout << n << "\n";
    }

    return 0;
}