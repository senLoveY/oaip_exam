#include <iostream>

using namespace std;

int main() {

    int n;
    cin>>n;

    int* m = new int[n];

    for(int i = 0;i < n; i++)
    {
        cin>>m[i];
    }

    int min_i;

    for(int i = 0; i<n-1;i++)
    {
        min_i = i;
        for(int j = i+1; j<n;j++)
        {
            if(m[min_i] > m[j])
            {
                min_i = j;
            }
            if(min_i != i){
                swap(m[min_i], m[i]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout<<m[i]<< ' ';

    }

delete[] m;

    return 0;
}
