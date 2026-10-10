#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5+5;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    vector<int>freq(MAXN, 0);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int tipos=0;
    long long int resp=0;
    for(int esq=0, dir=0; esq<n; esq++){
        while(tipos<k && dir<n){
            if (freq[a[dir]] == 0){
                tipos++;
            }
            freq[a[dir]]++;
            dir++;
        }
        if(tipos>=k){
            resp+=(n-dir+1);
        }
        freq[a[esq]]--;
        if(freq[a[esq]]==0){
            tipos--;
        }
    }

    cout << resp;
    return 0;
}
