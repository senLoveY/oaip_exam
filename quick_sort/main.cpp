#include <iostream>

using namespace std;

int n;
int *a;

void s_qsr(int left, int right) {
    int i = left, j = right;
    int x;
    x = a[(i + j) / 2];
    do {
        while (a[i] < x && i < right - 1) i++;
        while (a[j] > x && j > left + 1) j--;

        if (i <= j) {
            swap(a[i], a[j]);
        }
        i++;
        j--;

    } while (i <= j);
    if (left < j) {
        s_qsr(left, j);
    }
    if (i < right) {
        s_qsr(i, right);
    }
}

int main() {
    cin >> n;
    a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    s_qsr(0, n - 1); // Вызов быстрой сортировки

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    delete[] a;
    return 0;
}