#include <iostream>

using namespace std;

struct TNode {
    int inf;
    TNode *left;
    TNode *right;
};

struct TTree {
    TNode *root = nullptr;

    bool is_empty() {
        if (root) return false;
        else return true;
    }

    void push(int inf) {
        TNode *nu = new TNode;
        nu->inf = inf;
        nu->left = nullptr;
        nu->right = nullptr;

        if (!root) {
            root = nu;
            return;
        }

        TNode *pdel = nullptr;
        TNode *del = root;

        while (del) {
            pdel = del;
            if (inf < del->inf) {
                del = del->left;
            } else {
                del = del->right;
            }
        }

        if (inf < pdel->inf) {
            pdel->left = nu;
        } else {
            pdel->right = nu;
        }
    }

// симметричный обход дерева
    void print(TNode *p) {
        if (!p) return;
        print(p->left);
        cout << p->inf << " ";
        print(p->right);
    }

    TNode *search(int x) {
        TNode *p = root;
        while (p) {
            if (x == p->inf) {
                return p;
            }
            if (x < p->inf) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
    }


    void pop(int x) {
        TNode *del = root, *pdel = nullptr, *rep = nullptr, *prep = nullptr;

        // Поиск удаляемого узла
        while (del && del->inf != x) {
            pdel = del;
            if (x < del->inf) {
                del = del->left;
            } else {
                del = del->right;
            }
        }

        if (!del) {
            cout << endl << "Узел не найден" << endl;
            return;
        }

        // Поиск замещающего узла
        prep = del;
        if (!del->left) {
            rep = del->right;
        } else {
            rep = del->left;
            while (rep->right != nullptr) {
                prep = rep;
                rep = rep->right;
            }
        }

        // Замена узла
        if (rep) { // Если не лист
            if (prep->left == rep) {
                prep->left = rep->left;
            } else {
                prep->right = rep->left;
            }
            rep->right = del->right;
            rep->left = del->left;
        }

        // Подключение замещающего узла
        if (del == root) {
            root = rep; // Если удаляемый узел - корень дерева
        } else {
            if (pdel->left == del) {
                pdel->left = rep;
            } else {
                pdel->right = rep;
            }
        }

        // Удаление узла
        delete del;
    }

    int search_max() {
        TNode *p = root;
        while (p->right != nullptr) {
            p = p->right;
        }
        return p->inf;
    }

    int search_min() {
        TNode *p = root;
        while (p->left != nullptr) {
            p = p->left;
        }
        return p->inf;
    }


    TNode *pop_all(TNode *p) {
        if (!p) {
            return nullptr;
        }
        pop_all(p->left);
        pop_all(p->right);
        delete (p);
    }

};

int main() {

    TTree s;

    int n;
    cout << "insert amount of the tree nodes" << endl;
    cin >> n;

    int element;
    for (int i = 0; i < n; ++i) {
        cin >> element;
        s.push(element);
    }

    s.print(s.root);
    cout << endl;

    int del;
    cout << "insert the element to delete" << endl;
    cin >> del;
    s.pop(del);

    s.print(s.root);
    cout << endl;

    cout << "min = " << s.search_min() << endl;
    cout << "max = " << s.search_max() << endl;

    int f;
    cout << "insert the element to search" << endl;
    cin >> f;
    TNode *m = s.search(f);
    if (m) cout << m->inf << endl;
    s.root = s.pop_all(s.root);
    if (s.is_empty()) cout << "Tree removed";

    return 0;
}
