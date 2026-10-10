#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x;
    cin >> x;
    if (x == 5){
        cout << 7;
    }else{
        long long altura = 13 +(x-6)*6;
        cout << altura;
    }

    return 0;
}