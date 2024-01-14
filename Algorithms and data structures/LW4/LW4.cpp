#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//функция push добавляет значение в основной стек и в дополнительный, если число является 
// текущим максимумом или дополнительный стек пуст 
void push(stack<int>& mainStack, stack<int>& addStack, int num) {
    mainStack.push(num);
    if (addStack.empty() || num >= addStack.top()) {
        addStack.push(num);
    }
}

//функция pop удаляет значение из основного стека и из дополнительного, если число является текущим максимумом
void pop(stack<int>& mainStack, stack<int>& addStack) {
    if (mainStack.top() == addStack.top()) {
        addStack.pop();
    }
    mainStack.pop();
}

//функция max возвращает верхний элемент дополнительного стека (текущий максимум)
int max(stack<int>& addStack) {
    return addStack.top();
}

//функция command принимает команды и проверяет их на удовлетворение требованиям, вызывает соответствующие функции
void сommand(stack<int>& mainStack, stack<int>& addStack, string& operation, int& num, vector<int>& maxValues) {
    int repeat;

    do {
        cout << "Введите количество операций: ";
        cin >> repeat;
        if (cin.fail() || repeat < 1 || repeat > 400000) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Пожалуйста, введите целое число в диапазоне от 1 до 400000.\n";
        }
    } while (cin.fail() || repeat < 1 || repeat > 400000);

    for (int i = 0; i < repeat; i++) {
        cout << "Введите операцию: ";
        cin >> operation;

        if (operation == "push") {
            do {
                cin >> num;
                if (cin.fail() || num < 0 || num > 100000) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Некорректный ввод. Пожалуйста, введите целое число в диапазоне от 0 до 100000. Повторите операцию.\n";
                    i--;
                }
            } while (cin.fail() || num < 0 || num > 100000);
            push(mainStack, addStack, num);
        }
        else if (operation == "pop") {
            pop(mainStack, addStack);
        }
        else if (operation == "max") {
            maxValues.push_back(max(addStack));
        }
        else {
            cout << "Ошибка: некорректная операция. Пожалуйста, повторите ввод.\n";
            i--;
        }
    }
}

//функция output выводит на консоль значения max
void output(vector<int>& maxValues) {
    for (int i = 0; i < maxValues.size(); i++) {
        cout << maxValues[i] << endl;
    }
}

//функция exec инициализирует переменные и последовательно вызывает все функции, необходимые для работы программы
void exec() {
    stack<int> mainStack;
    stack<int> addStack;
    vector<int> maxValues;
    string operation;
    int num = 0;
    сommand(mainStack, addStack, operation, num, maxValues);
    output(maxValues);
}

//функция main является точкой входа в программу, устанавливает русскую локаль и вызывает функцию exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}