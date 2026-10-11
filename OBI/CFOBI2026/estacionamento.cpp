#include <iostream>

using namespace std;

int main() {
    int h;
    cin >> h;
    if(h==1){
        cout << 15 << "\n";
    }else{
        cout << 15+(h-1)*5 << "\n";
    }
    
    return 0;
}