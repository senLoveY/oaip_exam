#include <iostream>

using namespace std;

int n;
int *a;
int *c;

void slip(int left, int m, int right){
    int i = left, j = m+1, k = 0;
    while ((i <= m) && (j <= right)) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            i++;
            k++;
        } else {
            c[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= m){
        c[k] = a[i];
        i++;
        k++;
    }

    while (j <= right){
        c[k] = a[j];
        j++;
        k++;
    }

    for(k = 0, i = left; i<=right; i++, k++)
    {
        a[i] = c[k];
    }
}

void s_sl(int left, int right) {
    if (left < right) {
        int m = (left + right) / 2;
        s_sl(left, m);
        s_sl(m + 1, right);
        slip(left, m, right);
    }
}

int main() {
    cin >> n;
    a = new int[n];
    c = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    s_sl(0, n - 1); // Вызываем сортировку слиянием

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    delete[] a;
    delete[] c;
    return 0;
}