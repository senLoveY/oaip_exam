#include <iostream>

using namespace std;

struct TNode {
    int inf;
    TNode *a;
};

struct stack {
    TNode *top = nullptr; // указатель на вершину стека
    int size = 0; //количество элементов в стеке

    // проверка наличия элементов в стеке
    bool empty() {
        if (top) return false;
        else return true;
    }

    void push(int inf) {
        TNode *spt = new TNode;
        spt->inf = inf;
        spt->a = top;
        top = spt;
        size++;
    }

    // удаление элемента из стека
    void pop() {
        TNode *spt = top;
        top = top->a;
        delete spt;
        size--;
    }

    // вывод стека
    void print() {
        TNode *spt = top;
        while (spt != nullptr) {
            cout << spt->inf << " ";
            spt = spt->a;
        }
    }

    // поиск элемента с заданным ключем
    TNode *search(int x) {
        if (!top) return nullptr;
        TNode *spt = top;
        while (spt->inf != x && spt->a != nullptr) {
            spt = spt->a;
        }
        if (spt->inf == x) {
            return spt;
        } else {
            return nullptr;
        }
    }

    // поиск предыдущего элемента (исключая первый)
    TNode *search_p(int x) {
        if (!top || !top->a) return nullptr;
        TNode *spt = top;
        while (spt->a->inf != x && spt->a->a != nullptr) {
            spt = spt->a;
        }
        if (spt->a->inf == x) {
            return spt;
        } else {
            return nullptr;
        }
    }

    // удаление элемента с заданнм ключем
    void del(int x) {
        if (!top) return;
        if (top->inf == x) pop();
        TNode *spt, *spp;
        spp = search_p(x);
        spt = spp->a;
        spp->a = spp->a->a;
        delete spt;
    }

    // обмен следующих за указанным элементов
    void exchange(TNode *sp) {
        if (sp->a->a == nullptr) return; // добавил проврку на наличие элементов для избежания ошибок
        TNode *spt;
        spt = sp->a->a;
        sp->a->a = spt->a;
        spt->a = sp->a;
        sp->a = spt;
    }

};

int main() {

    stack s;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int inf;
        cin >> inf;
        s.push(inf);
    }

    s.print();
    int x1;
    cout << endl << "enter the element to search for:" << endl;
    cin >> x1;
    TNode *d1 = s.search(x1);
    cout << d1->inf << endl;
    TNode *d2 = s.search_p(x1);
    cout << d2->inf << endl;

    s.exchange(d2);
    s.print();

    int x2;
    cout << "enter the element to delete:" << endl;
    cin >> x2;
    s.del(x2);
    s.print();

    while (!s.empty()) {
        s.pop();
    }
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    }
    return 0;
}
