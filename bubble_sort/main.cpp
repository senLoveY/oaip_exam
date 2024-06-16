#include <iostream>

using namespace std;

int main() {

    int n;
    cin>>n;
    int * m = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>m[i];
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(m[i]>m[j]){
                swap(m[i],m[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<m[i]<<' ';
    }

    delete[] m;
    return 0;
}
