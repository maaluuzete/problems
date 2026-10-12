#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n == 1958 || n == 1962 || n == 1970 || n == 1994 || n == 2002){
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}