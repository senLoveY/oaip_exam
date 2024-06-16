#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int *m = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin>>m[i];
    }

    int t, j;
    for(int step = n/2; step > 0; step--){
        for(int i = step; i<n; i++){
          t = m[i];
          for(j = i - step; j >= 0 && t < m[j]; j -= step){
              m[j+step]=m[j];
          }
          m[j+step] = t;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << m[i] << ' ';
    }

    delete[]m;
    return 0;
}
