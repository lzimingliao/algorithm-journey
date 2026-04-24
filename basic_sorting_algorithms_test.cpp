#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    for (int minIndex, i = 0; i < (int)arr.size() - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < (int)arr.size(); j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(vector<int>& arr) {
    for (int end = (int)arr.size() - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        }
    }
}

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < (int)arr.size(); i++)
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) swap(arr[j], arr[j + 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N = 200;
    int V = 1000;
    int testTimes = 50000;
    cout << "测试开始\n";
    while (testTimes--) {
        int n = rand() % N + 1;
        int v = rand() % V + 1;
        vector<int> arr(n), arr1(n), arr2(n), arr3(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % v + 1;
            arr1[i] = arr[i];
            arr2[i] = arr[i];
            arr3[i] = arr[i];
        }
        selectionSort(arr1);
        bubbleSort(arr2);
        insertionSort(arr3);
        if (arr1 != arr2 || arr1 != arr3) cout << "测试失败\n";
    }
    cout << "测试结束\n";
    return 0;
}
