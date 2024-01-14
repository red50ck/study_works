#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//cоздание структуры пакета
struct Packet {
    long long int arrival_time;
    long long int duration;
};


//функция inputData инициализирует переменные и проверяет их на ограничения, используя циклы do-while и флаги
void inputData(int& size, int& n, vector<Packet>& packets, bool validInput) {
    do {
        cout << "Введите размер буфера: ";
        cin >> size;
        if (size < 1 || size > 100000) {
            cerr << "Неверное значение, попробуйте ещё раз!" << endl;
        }
    } while (size < 1 || size > 100000);

    do {
        cout << "Введите число пакетов: ";
        cin >> n;
        if (n < 0 || n > 100000) {
            cerr << "Неверное значение, попробуйте ещё раз!" << endl;
        }
        if (n == 0) {
            cerr << "Пакетов нет. Программа завершена." << endl;
            exit(0);
        }
    } while (n < 0 || n > 100000);

    packets.resize(n);
    do {
        validInput = true;
        cout << "Введите время поступления " << n << " пакетов через пробел в порядке возрастания: ";
        for (int i = 0; i < n; ++i) {
            cin >> packets[i].arrival_time;
            if (packets[i].arrival_time < 0 || packets[i].arrival_time > 1000000) {
                cerr << "Неверное значение " << packets[i].arrival_time << ". Пожалуйста, повторите ввод." << endl;
                validInput = false;
                break;
            }
            if (i > 0 && packets[i-1].arrival_time > packets[i].arrival_time) {
                cerr << "Значения введены не в порядке возрастания. Неверное значение: " << packets[i].arrival_time
                    << ". Пожалуйста, повторите ввод" << endl;
                validInput = false;
                break;
            }
        }
        if (!validInput) {
            cin.clear();
            cin.ignore(numeric_limits < streamsize>::max(), '\n');
        }
    } while (!validInput);

    do {
        validInput = true;
        cout << "Введите длительность обработки " << n << " пакетов через пробел: ";
        for (int i = 0; i < n; ++i) {
            cin >> packets[i].duration;
            if (packets[i].duration < 0 || packets[i].duration > 1000) {
                cerr << "Неверное значение " << packets[i].duration << ". Пожалуйста, повторите ввод." << endl;
                validInput = false;
                break;
            }
        }
        if (!validInput) {
            cin.clear();
            cin.ignore(numeric_limits < streamsize>::max(), '\n');
        }
    } while (!validInput);

}

//функция processPackets определяет очередь обработки пакетов, фиксирует время начала обработки пакета или возвращает -1, 
// если тот был отброшен, выводит полученные значения времени на консоль
void processPackets(int size, int n, vector<Packet>& packets) {
    queue<Packet> buffer;
    vector<long long int> outputArrival(n, -1);
    long long int currentTime = 0;

    for (int i = 0; i < n || !buffer.empty(); ) {
        while (!buffer.empty() && buffer.front().arrival_time + buffer.front().duration <= currentTime) {
            buffer.pop();
        }
        while (i < n && (buffer.empty() || buffer.front().arrival_time + buffer.front().duration > packets[i].arrival_time)) {
            if (buffer.size() < size) {
                if (buffer.empty()) {
                    currentTime = max(currentTime, packets[i].arrival_time);
                }
                buffer.push(packets[i]);
                outputArrival[i] = currentTime;
                currentTime += packets[i].duration;
            }
            ++i;
        }
    }

    //вывод данных
    for (long long int time : outputArrival) {
        cout << time << endl;
    }
}

//функция exec инициализирует переменные и последовательно вызывает все функции, необходимые для работы программы
void exec() {
    int size;
    int n;
    bool validInput = false;
    vector<Packet> packets;
    inputData(size, n, packets, validInput);
    processPackets(size, n, packets);
}

//функция main является точкой входа в программу, устанавливает русскую локаль и вызывает функцию exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}
