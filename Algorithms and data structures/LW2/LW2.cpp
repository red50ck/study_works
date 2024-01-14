
#include <iostream>

using namespace std;

//создаем структуру узла дерева, содержащую в себе значение и ссылки на потомков
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

//рекурсивная функция insert используется для создания и вставки нового узла в бинарное 
// дерево (меньше текущего корня - налево, больше - направо)
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

//функция createTree принимает в себя введенные через консоль значения и строит бинарное дерево с помощью функции insert
TreeNode* createTree(int n, int parents[]) {
	TreeNode* root = nullptr;
	for (int i = 0; i < n; i++) {
		root = insert(root, parents[i]);
	}
	return root;
}

//функция treeHeight принимает в себя значение корня дерева, рекурсивно подсчитывает и возвращает максимальную 
// высоту правого и левого поддеревьев
int treeHeight(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	
	int leftHeight = treeHeight(root->left);
	int rightHeight = treeHeight(root->right);
	return 1 + max(leftHeight, rightHeight);
}

//функция exec принимает в себя значения входа: n - количество элементов в дереве и parents - значения элементов, 
//после чего последовательно вызывает все функции, необходимые для выполнения программы
void exec(){
	int n;
	do {
		cout << "Введите количество элементов дерева:" << endl;
		cin >> n;
		if (n < 1 || n > 100000) {
			cerr << "Неверное значение, попробуйте ещё раз!" << endl;
		}
	} while (n < 1 || n > 100000);

	int* parents = new int[n];
	cout << "Введите значения элементов дерева через пробел: " << endl;
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
