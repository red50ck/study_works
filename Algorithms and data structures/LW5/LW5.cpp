#include <iostream>
#include <deque>
#include <vector>

using namespace std;

//функция readData принимает с консоли значения размера массива и его значений, размера массива и проверяет их на ограничения
void readData(int& n, int& m, vector<int>& arr) {
    cout << "Введите размер массива (n): ";
    cin >> n;
    if (n < 1 || n > 100000) {
        cerr << "Неверное значение, попробуйте ещё раз!" << endl;
        exit(1);
    }

    cout << "Введите значения массива: ";
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 100000) {
            cerr << "Неверное значение " << arr[i] << ". Пожалуйста, повторите ввод." << endl;
            exit(1);
        }
    }

    do {
        cout << "Введите размер окна (m): ";
        cin >> m;
        if (m < 1 || m > n) {
            cerr << "Неверное значение, попробуйте ещё раз!" << endl;
        }
    } while (m < 1 || m > n);
}

//функция findMaxInSlidingWindow создает очередь deque и добавляет в нее элементы так, что первый элемент всегда является максимальным
vector<int> findMaxInSlidingWindow(const vector<int>& nums, int windowSize) {
    vector<int> result;
    deque<int> window;

    for (int i = 0; i < windowSize; ++i) {
        while (!window.empty() && nums[i] >= nums[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
    }

    for (int i = windowSize; i < nums.size(); ++i) {
        result.push_back(nums[window.front()]);

        while (!window.empty() && window.front() <= i - windowSize) {
            window.pop_front();
        }

        while (!window.empty() && nums[i] >= nums[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
    }

    result.push_back(nums[window.front()]);

    return result;
}

//функция printVector выводит все элементы результирующего вектора на консоль
void printVector(const vector<int>& result) {
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

//функция exec инициализирует переменные и последовательно вызывает все функции, необходимые для работы программы
void exec() {
    int n = 0;
    vector<int> arr;
    int m = 0;
    readData(n, m, arr);
    vector<int> result = findMaxInSlidingWindow(arr, m);

    cout << "Максимумы в скользящем окне: ";
    printVector(result);
}

//функция main является точкой входа в программу, устанавливает русскую локаль и вызывает функцию exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}
