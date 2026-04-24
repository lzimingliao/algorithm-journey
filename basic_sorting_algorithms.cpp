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

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        a[i] = val[i];
        b[i] = val[i];
        c[i] = val[i];
    }

    selectionSort(a);
    for (int i = 0; i < n; i++) cout << a[i] << (i == n - 1 ? "\n" : " ");

    bubbleSort(b);
    for (int i = 0; i < n; i++) cout << b[i] << (i == n - 1 ? "\n" : " ");

    insertionSort(c);
    for (int i = 0; i < n; i++) cout << c[i] << (i == n - 1 ? "\n" : " ");

    return 0;
}
