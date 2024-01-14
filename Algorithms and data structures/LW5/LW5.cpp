#include <iostream>
#include <deque>
#include <vector>

using namespace std;

//������� readData ��������� � ������� �������� ������� ������� � ��� ��������, ������� ������� � ��������� �� �� �����������
void readData(int& n, int& m, vector<int>& arr) {
    cout << "������� ������ ������� (n): ";
    cin >> n;
    if (n < 1 || n > 100000) {
        cerr << "�������� ��������, ���������� ��� ���!" << endl;
        exit(1);
    }

    cout << "������� �������� �������: ";
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 100000) {
            cerr << "�������� �������� " << arr[i] << ". ����������, ��������� ����." << endl;
            exit(1);
        }
    }

    do {
        cout << "������� ������ ���� (m): ";
        cin >> m;
        if (m < 1 || m > n) {
            cerr << "�������� ��������, ���������� ��� ���!" << endl;
        }
    } while (m < 1 || m > n);
}

//������� findMaxInSlidingWindow ������� ������� deque � ��������� � ��� �������� ���, ��� ������ ������� ������ �������� ������������
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

//������� printVector ������� ��� �������� ��������������� ������� �� �������
void printVector(const vector<int>& result) {
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

//������� exec �������������� ���������� � ��������������� �������� ��� �������, ����������� ��� ������ ���������
void exec() {
    int n = 0;
    vector<int> arr;
    int m = 0;
    readData(n, m, arr);
    vector<int> result = findMaxInSlidingWindow(arr, m);

    cout << "��������� � ���������� ����: ";
    printVector(result);
}

//������� main �������� ������ ����� � ���������, ������������� ������� ������ � �������� ������� exec
int main() {
    setlocale(LC_ALL, "Russian");
    exec();
    return 0;
}
