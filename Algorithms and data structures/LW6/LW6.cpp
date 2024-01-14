#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//������� readData ��������� � ������� ������ ������� � ��� �������� � ��������� �� �� ������������ ������������
void readData(vector<int>& data, int& n, vector<pair<int, int>>& swaps) {
    cout << "������� ������ �������: ";
    cin >> n;
    if (n < 1 || n > 100000) {
        cerr << "�������� ��������, ���������� ��� ���!" << endl;
        exit(1);
    }

    data.resize(n);
    cout << "������� �������� �������: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        if (data[i] < 0 || data[i] > 1000000000) {
            cerr << "�������� �������� " << data[i] << ". ����������, ��������� ����." << endl;
            exit(1);
        }
    }
}

//������� sorting ������������ �������� ������� ���, ����� ������������� �������� ���-��� � ��������� ��� ������������
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

//������� buildHeap ����������� ������� ������ � ����������� ����
void buildHeap(vector<int>& data, int n, vector<pair<int, int>>& swaps) {
    for (int i = n / 2 - 1; i >= 0; i--)
        sorting(data, n, i, swaps);
}

//������� printSwaps ������� ���������� ������������ � ���� ������������, ������� ����� ������� ��� �������������� ������� � ����������� ����
void printSwaps(const vector<pair<int, int>>& swaps) {
    cout << swaps.size() << endl;
    for (const auto& swap : swaps)
        cout << swap.first << " " << swap.second << endl;
}

//������� exec �������������� ���������� � ��������������� �������� ��� �������, ����������� ��� ������ ���������
void exec() {
    vector<int> data;
    vector<pair<int, int>> swaps;
    int n;

    readData(data, n, swaps);
    buildHeap(data, n, swaps);
    printSwaps(swaps);
}

//������� main �������� ������ ����� � ���������, ������������� ������� ������ � �������� ������� exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}
