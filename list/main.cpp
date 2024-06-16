#include <iostream>

using namespace std;

struct TNode {
    int inf;
    TNode *left;
    TNode *right;
};

struct list {
    TNode *front = nullptr; // указатель на начало списка
    TNode *back = nullptr; // указатель на конец списка

    // проверка наличия элементов в списке
    bool empty() {
        if (front) return false;
        else return true;
    }

    // добавление элемента в список
    void push(int inf) {
        TNode *spt = new TNode;
        spt->inf = inf;
        spt->right = nullptr;
        spt->left = nullptr; // Инициализация left
        // если элементы отсутствуют
        if (!front) {
            front = back = spt;
            return;
        }
        back->right = spt;
        spt->left = back;
        back = spt;
    }

    // удаление элемента из списка
    void pop() {
        if (front == nullptr) return; // Проверка на пустую очередь
        TNode *spt = front;
        front = front->right;
        delete spt;
        if (!front) {
            back = nullptr;
        } else {
            front->left = nullptr;
        }
    }

    // вывод списка
    void print() {
        TNode *spt = front;
        while (spt != nullptr) {
            cout << spt->inf << " ";
            spt = spt->right;
        }
    }

    // поиск элемента с заданным ключем
    TNode *search(int x) {
        if (!front) return nullptr;
        TNode *spt = front;
        while (spt->inf != x && spt->right != nullptr) {
            spt = spt->right;
        }
        if (spt->inf == x) {
            return spt;
        } else {
            return nullptr;
        }
    }

    // удаление элемента с заданным ключем
    void del(int x) {
        TNode *spt = search(x);
        if (!spt) return;

        // Удаление элемента
        if (spt->left) {
            spt->left->right = spt->right;
        } else {
            front = spt->right;
        }

        if (spt->right) {
            spt->right->left = spt->left;
        } else {
            back = spt->left;
        }

        delete spt;
    }

    // добавление элемента после заданного
    void push_left(TNode *spp, int inf) {
        if (spp == nullptr) return; // Проверка на пустой список
        TNode *spt = new TNode;
        spt->inf = inf;
        spt->right = spp->right;
        spt->left = spp;
        spp->right = spt;
        if (spt->right) {
            spt->right->left = spt;
        }
        if (spp == back) {
            back = spt;
        }
    }

};

int main() {

    list s;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int inf;
        cin >> inf;
        s.push(inf);
    }

    s.print();
    cout << endl << "Insert element to delete:" << endl;
    int x;
    cin >> x;
    s.del(x);
    s.print();
    cout << endl;
    cout << endl << "Insert element to push:" << endl;
    int x1;
    cin >> x1;
    cout << endl << "Insert element to search for:" << endl;
    int x2;
    cin >> x2;

    s.push_left(s.search(x2), x1);
    s.print();

    while (!s.empty()) {
        s.pop();
    }
    if (s.empty()) {
        cout << endl << "List is empty" << endl;
    }
    return 0;
}