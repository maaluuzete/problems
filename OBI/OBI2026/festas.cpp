#include <iostream>

using namespace std;

int main(){
    int da, ma, db, mb;
    cin >> da >> ma >> db >> mb;

    if(ma<mb){
        cout << "A\n";
    }else if(mb<ma){
        cout << "B\n";
    }else if(da<db){
        cout << "A\n";
    }else{
        cout << "B\n";
    }

    return 0;
}
