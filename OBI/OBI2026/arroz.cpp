#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a, b;
    cin >> n >> a >> b;
    if (5*a<=b){
        cout << n*a << "\n";
    }else{
        long long op1 = ((n+4)/5) *b;
        long long op2 = (n/5)*b + (n%5) *a;
        cout << min(op1, op2) << "\n";
    }

    return 0;
}
