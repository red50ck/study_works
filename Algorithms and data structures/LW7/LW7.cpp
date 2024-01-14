#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//структура PhoneBook содержит в себе такие команды как add, del и find
struct PhoneBook {
    unordered_map<string, string> numbers;

    void add(const string& number, const string& name) {
        numbers[number] = name;
    }

    void del(const string& number) {
        numbers.erase(number);
    }

    string find(const string& number) {
        auto it = numbers.find(number);
        if (it != numbers.end()) {
            return it->second;
        }
        else {
            return "not found";
        }
    }
};

//функция readData принимает с консоли количество запросов и сами запросы и вызывает соответствующую функцию
void readData(int& n, PhoneBook& phoneBook, vector<string>& results) {
    cout << "Введите количество запросов: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Введите запрос: ";
        string query;
        cin >> query;

        if (query == "add") {
            string number, name;
            cin >> number >> name;
            phoneBook.add(number, name);
        }
        else if (query == "del") {
            string number;
            cin >> number;
            phoneBook.del(number);
        }
        else if (query == "find") {
            string number;
            cin >> number;
            results.push_back(phoneBook.find(number));
        }
        else if (query != "find" || query != "add" || query != "del") {
            cout << "Команда не найдена. Пожалуйста, повторите ввод. ";
        }
    }
}

//функция printResults выводит на консоль содержимое вектора results, в котором хранятся ответы на запрос find
void printResults(const vector<string>& results) {
    for (const string& result : results) {
        cout << result << endl;
    }
}

//функция exec инициализирует структуру, переменные и последовательно вызывает все функции, необходимые для работы программы
void exec() {
    int n;
    PhoneBook phoneBook;
    vector<string> results;
    readData(n, phoneBook, results);
    printResults(results);
}

//функция main является точкой входа в программу, устанавливает русскую локаль и вызывает функцию exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}
