#include <iostream>

using namespace std;

struct TNode {
    int inf;
    TNode *a;
};

struct queue {
    TNode *front = nullptr; // указатель на начало очереди
    TNode *back = nullptr; // указатель на конец очереди

    // проверка наличия элементов в очереди
    bool empty() {
        if (front) return false;
        else return true;
    }

    // добавление элемента в очередь
    void push(int inf) {
        TNode *spt = new TNode;
        spt->inf = inf;
        spt->a = nullptr;
        // если элементы отсутсвуют
        if (!front) {
            front = back = spt;
        } else {
            back->a = spt;
            back = spt;
        }
    }

    // удаление элемента из очереди
    void pop() {
        if (front == nullptr) return; // Проверка на пустую очередь
        TNode *spt = front;
        front = front->a;
        delete spt;
        if (!front) {
            back = nullptr;
        }
    }

    // вывод очереди
    void print() {
        TNode *spt = front;
        while (spt != nullptr) {
            cout << spt->inf << " ";
            spt = spt->a;
        }
    }

};

int main() {

    queue s;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int inf;
        cin >> inf;
        s.push(inf);
    }

    s.print();

    while (!s.empty()) {
        s.pop();
    }
    if (s.empty()) {
        cout << "Queue is empty" << endl;
    }
    return 0;
}