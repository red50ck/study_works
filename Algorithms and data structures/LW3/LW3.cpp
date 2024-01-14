#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//c������� ��������� ������
struct Packet {
    long long int arrival_time;
    long long int duration;
};


//������� inputData �������������� ���������� � ��������� �� �� �����������, ��������� ����� do-while � �����
void inputData(int& size, int& n, vector<Packet>& packets, bool validInput) {
    do {
        cout << "������� ������ ������: ";
        cin >> size;
        if (size < 1 || size > 100000) {
            cerr << "�������� ��������, ���������� ��� ���!" << endl;
        }
    } while (size < 1 || size > 100000);

    do {
        cout << "������� ����� �������: ";
        cin >> n;
        if (n < 0 || n > 100000) {
            cerr << "�������� ��������, ���������� ��� ���!" << endl;
        }
        if (n == 0) {
            cerr << "������� ���. ��������� ���������." << endl;
            exit(0);
        }
    } while (n < 0 || n > 100000);

    packets.resize(n);
    do {
        validInput = true;
        cout << "������� ����� ����������� " << n << " ������� ����� ������ � ������� �����������: ";
        for (int i = 0; i < n; ++i) {
            cin >> packets[i].arrival_time;
            if (packets[i].arrival_time < 0 || packets[i].arrival_time > 1000000) {
                cerr << "�������� �������� " << packets[i].arrival_time << ". ����������, ��������� ����." << endl;
                validInput = false;
                break;
            }
            if (i > 0 && packets[i-1].arrival_time > packets[i].arrival_time) {
                cerr << "�������� ������� �� � ������� �����������. �������� ��������: " << packets[i].arrival_time
                    << ". ����������, ��������� ����" << endl;
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
        cout << "������� ������������ ��������� " << n << " ������� ����� ������: ";
        for (int i = 0; i < n; ++i) {
            cin >> packets[i].duration;
            if (packets[i].duration < 0 || packets[i].duration > 1000) {
                cerr << "�������� �������� " << packets[i].duration << ". ����������, ��������� ����." << endl;
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

//������� processPackets ���������� ������� ��������� �������, ��������� ����� ������ ��������� ������ ��� ���������� -1, 
// ���� ��� ��� ��������, ������� ���������� �������� ������� �� �������
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

    //����� ������
    for (long long int time : outputArrival) {
        cout << time << endl;
    }
}

//������� exec �������������� ���������� � ��������������� �������� ��� �������, ����������� ��� ������ ���������
void exec() {
    int size;
    int n;
    bool validInput = false;
    vector<Packet> packets;
    inputData(size, n, packets, validInput);
    processPackets(size, n, packets);
}

//������� main �������� ������ ����� � ���������, ������������� ������� ������ � �������� ������� exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}
