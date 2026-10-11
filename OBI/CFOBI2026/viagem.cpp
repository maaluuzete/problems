#include <iostream>

using namespace std;

int main() {
    int c, d;
    cin >> c >> d; 
    int autonomia =c*12;
    
    if(autonomia >= d){
        cout << "S\n";
    }else{
        cout << "N\n";
    }
    
    return 0;
}