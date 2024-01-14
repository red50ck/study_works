#include <iostream>
#include <vector>

using namespace std;

//создание структуры, в которой у каждого узла есть ключ (key), а также индексы левого (left) и правого (right) дочерних узлов в векторе дерева
struct Node {
    int key;
    int left;
    int right;

    Node(int k, int l, int r) : key(k), left(l), right(r) {}
};

//функция inOrderTraversal сначала обходит левое поддерево, затем посещает узел, а затем обходит правое поддерево
void inOrderTraversal(const vector<Node>& tree, int index, vector<int>& result) {
    if (index != -1) {
        inOrderTraversal(tree, tree[index].left, result);
        result.push_back(tree[index].key);
        inOrderTraversal(tree, tree[index].right, result);
    }
}

//функция preOrderTraversal сначала посещает узел, затем обходит левое поддерево, а затем правое поддерево
void preOrderTraversal(const vector<Node>& tree, int index, vector<int>& result) {
    if (index != -1) {
        result.push_back(tree[index].key);
        preOrderTraversal(tree, tree[index].left, result);
        preOrderTraversal(tree, tree[index].right, result);
    }
}

//функция postOrderTraversal сначала обходит левое поддерево, затем правое поддерево, а затем посещает узел
void postOrderTraversal(const vector<Node>& tree, int index, vector<int>& result) {
    if (index != -1) {
        postOrderTraversal(tree, tree[index].left, result);
        postOrderTraversal(tree, tree[index].right, result);
        result.push_back(tree[index].key);
    }
}

//функция readTree считывает количество узлов, узлы и сохраняет их в вектор 
vector<Node> readTree() {
    cout << "Введите количество вершин: ";
    int n;
    cin >> n;

    cout << "Введите значения вершин (или -1, если потомка нет): " << endl;
    vector<Node> tree;
    for (int i = 0; i < n; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.emplace_back(key, left, right);
    }

    return tree;
}

//функция printResults выводит на консоль все значения из вектора result
void printResults(const vector<int>& result) {
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
}

//функция exec инициализирует переменные и последовательно вызывает все функции, необходимые для работы программы
void exec() {
    vector<Node> tree = readTree();

    vector<int> inOrderResult, preOrderResult, postOrderResult;

    inOrderTraversal(tree, 0, inOrderResult);
    preOrderTraversal(tree, 0, preOrderResult);
    postOrderTraversal(tree, 0, postOrderResult);

    printResults(inOrderResult);
    printResults(preOrderResult);
    printResults(postOrderResult);
}

//функция main является точкой входа в программу, устанавливает русскую локаль и вызывает функцию exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}
