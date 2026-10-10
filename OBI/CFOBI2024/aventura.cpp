#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    long long x=0, y=0;
    int direcao = 0; 
    int dx[]={0, 1, 0, -1};
    int dy[]={1, 0, -1, 0};

    for(int i=0; i<t; i++){
        char k;
        cin >> k;
        if(k == 'M'){
            long long n;
            cin >> n;
            x+=dx[direcao] *n;
            y+=dy[direcao] *n;
        }else if(k=='G'){
            int p;
            cin >> p;
            int giros=p/90;
            direcao=(direcao+giros)%4;
        }
    }

    cout << x << " " << y <<"\n";

    return 0;
}