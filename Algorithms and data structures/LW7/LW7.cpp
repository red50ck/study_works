#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//��������� PhoneBook �������� � ���� ����� ������� ��� add, del � find
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

//������� readData ��������� � ������� ���������� �������� � ���� ������� � �������� ��������������� �������
void readData(int& n, PhoneBook& phoneBook, vector<string>& results) {
    cout << "������� ���������� ��������: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "������� ������: ";
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
            cout << "������� �� �������. ����������, ��������� ����. ";
        }
    }
}

//������� printResults ������� �� ������� ���������� ������� results, � ������� �������� ������ �� ������ find
void printResults(const vector<string>& results) {
    for (const string& result : results) {
        cout << result << endl;
    }
}

//������� exec �������������� ���������, ���������� � ��������������� �������� ��� �������, ����������� ��� ������ ���������
void exec() {
    int n;
    PhoneBook phoneBook;
    vector<string> results;
    readData(n, phoneBook, results);
    printResults(results);
}

//������� main �������� ������ ����� � ���������, ������������� ������� ������ � �������� ������� exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}
