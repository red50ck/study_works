#include <iostream>
#include <vector>

using namespace std;

//�������� ���������, � ������� � ������� ���� ���� ���� (key), � ����� ������� ������ (left) � ������� (right) �������� ����� � ������� ������
struct Node {
    int key;
    int left;
    int right;

    Node(int k, int l, int r) : key(k), left(l), right(r) {}
};

//������� inOrderTraversal ������� ������� ����� ���������, ����� �������� ����, � ����� ������� ������ ���������
void inOrderTraversal(const vector<Node>& tree, int index, vector<int>& result) {
    if (index != -1) {
        inOrderTraversal(tree, tree[index].left, result);
        result.push_back(tree[index].key);
        inOrderTraversal(tree, tree[index].right, result);
    }
}

//������� preOrderTraversal ������� �������� ����, ����� ������� ����� ���������, � ����� ������ ���������
void preOrderTraversal(const vector<Node>& tree, int index, vector<int>& result) {
    if (index != -1) {
        result.push_back(tree[index].key);
        preOrderTraversal(tree, tree[index].left, result);
        preOrderTraversal(tree, tree[index].right, result);
    }
}

//������� postOrderTraversal ������� ������� ����� ���������, ����� ������ ���������, � ����� �������� ����
void postOrderTraversal(const vector<Node>& tree, int index, vector<int>& result) {
    if (index != -1) {
        postOrderTraversal(tree, tree[index].left, result);
        postOrderTraversal(tree, tree[index].right, result);
        result.push_back(tree[index].key);
    }
}

//������� readTree ��������� ���������� �����, ���� � ��������� �� � ������ 
vector<Node> readTree() {
    cout << "������� ���������� ������: ";
    int n;
    cin >> n;

    cout << "������� �������� ������ (��� -1, ���� ������� ���): " << endl;
    vector<Node> tree;
    for (int i = 0; i < n; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.emplace_back(key, left, right);
    }

    return tree;
}

//������� printResults ������� �� ������� ��� �������� �� ������� result
void printResults(const vector<int>& result) {
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
}

//������� exec �������������� ���������� � ��������������� �������� ��� �������, ����������� ��� ������ ���������
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

//������� main �������� ������ ����� � ���������, ������������� ������� ������ � �������� ������� exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}
