
#include <iostream>

using namespace std;

//������� ��������� ���� ������, ���������� � ���� �������� � ������ �� ��������
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

//����������� ������� insert ������������ ��� �������� � ������� ������ ���� � �������� 
// ������ (������ �������� ����� - ������, ������ - �������)
TreeNode* insert(TreeNode* root, int value) {
	if (root == nullptr) {
		return new TreeNode(value);
	}
	if (value < root->data) {
		root->left = insert(root->left, value);
	}
	else if (value > root->data) {
		root->right = insert(root->right, value);
	}
	return root;
};

//������� createTree ��������� � ���� ��������� ����� ������� �������� � ������ �������� ������ � ������� ������� insert
TreeNode* createTree(int n, int parents[]) {
	TreeNode* root = nullptr;
	for (int i = 0; i < n; i++) {
		root = insert(root, parents[i]);
	}
	return root;
}

//������� treeHeight ��������� � ���� �������� ����� ������, ���������� ������������ � ���������� ������������ 
// ������ ������� � ������ �����������
int treeHeight(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	
	int leftHeight = treeHeight(root->left);
	int rightHeight = treeHeight(root->right);
	return 1 + max(leftHeight, rightHeight);
}

//������� exec ��������� � ���� �������� �����: n - ���������� ��������� � ������ � parents - �������� ���������, 
//����� ���� ��������������� �������� ��� �������, ����������� ��� ���������� ���������
void exec(){
	int n;
	do {
		cout << "������� ���������� ��������� ������:" << endl;
		cin >> n;
		if (n < 1 || n > 100000) {
			cerr << "�������� ��������, ���������� ��� ���!" << endl;
		}
	} while (n < 1 || n > 100000);

	int* parents = new int[n];
	cout << "������� �������� ��������� ������ ����� ������: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> parents[i];
	}

	TreeNode* root = createTree(n, parents);
	cout << treeHeight(root) << endl;

	delete[] parents;
	return;
};
 

int main() {
	setlocale(LC_ALL, "Russian");
	exec();
	return 0;
}
