#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//функция readData принимает с консоли размер массива и его значения и проверяет их на соответствие ограничениям
void readData(vector<int>& data, int& n, vector<pair<int, int>>& swaps) {
    cout << "Введите размер массива: ";
    cin >> n;
    if (n < 1 || n > 100000) {
        cerr << "Неверное значение, попробуйте ещё раз!" << endl;
        exit(1);
    }

    data.resize(n);
    cout << "Введите значения массива: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        if (data[i] < 0 || data[i] > 1000000000) {
            cerr << "Неверное значение " << data[i] << ". Пожалуйста, повторите ввод." << endl;
            exit(1);
        }
    }
}

//функция sorting переставляет элементы массива так, чтобы удовлетворять свойству мин-куч и сохраняет все перестановки
void sorting(vector<int>& data, int n, int i, vector<pair<int, int>>& swaps) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && data[left] < data[smallest])
        smallest = left;

    if (right < n && data[right] < data[smallest])
        smallest = right;

    if (smallest != i) {
        swaps.push_back(make_pair(i, smallest));
        swap(data[i], data[smallest]);
        sorting(data, n, smallest, swaps);
    }
}

//функция buildHeap преобразует входной массив в минимальную кучу
void buildHeap(vector<int>& data, int n, vector<pair<int, int>>& swaps) {
    for (int i = n / 2 - 1; i >= 0; i--)
        sorting(data, n, i, swaps);
}

//функция printSwaps выводит количество перестановок и сами перестановки, которые нужно сделать для преобразования массива в минимальную кучу
void printSwaps(const vector<pair<int, int>>& swaps) {
    cout << swaps.size() << endl;
    for (const auto& swap : swaps)
        cout << swap.first << " " << swap.second << endl;
}

//функция exec инициализирует переменные и последовательно вызывает все функции, необходимые для работы программы
void exec() {
    vector<int> data;
    vector<pair<int, int>> swaps;
    int n;

    readData(data, n, swaps);
    buildHeap(data, n, swaps);
    printSwaps(swaps);
}

//функция main является точкой входа в программу, устанавливает русскую локаль и вызывает функцию exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}
