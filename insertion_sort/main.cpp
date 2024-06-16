#include <iostream>

using namespace std;

int main() {

    int n;
    cin>>n;
    int* m = new int[n];

    for (int i = 0; i < n; i++) {
        cin>>m[i];
    }

    for(int i = 1; i < n; i++){
        for(int j = i; j > 0 && m[j-1] > m[j]; j--){
            swap(m[j-1],m[j]);
        }
    }

    for(int i = 0; i < n; i++){
        cout<<m[i]<<' ';
    }

delete[] m;

    return 0;
}
