#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//������� push ��������� �������� � �������� ���� � � ��������������, ���� ����� �������� 
// ������� ���������� ��� �������������� ���� ���� 
void push(stack<int>& mainStack, stack<int>& addStack, int num) {
    mainStack.push(num);
    if (addStack.empty() || num >= addStack.top()) {
        addStack.push(num);
    }
}

//������� pop ������� �������� �� ��������� ����� � �� ���������������, ���� ����� �������� ������� ����������
void pop(stack<int>& mainStack, stack<int>& addStack) {
    if (mainStack.top() == addStack.top()) {
        addStack.pop();
    }
    mainStack.pop();
}

//������� max ���������� ������� ������� ��������������� ����� (������� ��������)
int max(stack<int>& addStack) {
    return addStack.top();
}

//������� command ��������� ������� � ��������� �� �� �������������� �����������, �������� ��������������� �������
void �ommand(stack<int>& mainStack, stack<int>& addStack, string& operation, int& num, vector<int>& maxValues) {
    int repeat;

    do {
        cout << "������� ���������� ��������: ";
        cin >> repeat;
        if (cin.fail() || repeat < 1 || repeat > 400000) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������������ ����. ����������, ������� ����� ����� � ��������� �� 1 �� 400000.\n";
        }
    } while (cin.fail() || repeat < 1 || repeat > 400000);

    for (int i = 0; i < repeat; i++) {
        cout << "������� ��������: ";
        cin >> operation;

        if (operation == "push") {
            do {
                cin >> num;
                if (cin.fail() || num < 0 || num > 100000) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "������������ ����. ����������, ������� ����� ����� � ��������� �� 0 �� 100000. ��������� ��������.\n";
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
            cout << "������: ������������ ��������. ����������, ��������� ����.\n";
            i--;
        }
    }
}

//������� output ������� �� ������� �������� max
void output(vector<int>& maxValues) {
    for (int i = 0; i < maxValues.size(); i++) {
        cout << maxValues[i] << endl;
    }
}

//������� exec �������������� ���������� � ��������������� �������� ��� �������, ����������� ��� ������ ���������
void exec() {
    stack<int> mainStack;
    stack<int> addStack;
    vector<int> maxValues;
    string operation;
    int num = 0;
    �ommand(mainStack, addStack, operation, num, maxValues);
    output(maxValues);
}

//������� main �������� ������ ����� � ���������, ������������� ������� ������ � �������� ������� exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}